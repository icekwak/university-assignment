#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/un.h>
#include <fcntl.h>

#define SOCKET_NAME "q04_socket"
#define SIZE 256
#define BYTE 16

int main() {
	struct sockaddr_un ser, cli;
	int s_sock, a_sock;
	int len, clen;
	char r_buf[SIZE];
	char s_buf[SIZE];
	int fd;
	int n;

	if((s_sock = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
		perror("socket");
		exit(1);
	}

	memset((char*)&ser, 0, sizeof(struct sockaddr_un));
	ser.sun_family = AF_UNIX;
	strcpy(ser.sun_path, SOCKET_NAME);
	len = sizeof(ser.sun_family) + strlen(ser.sun_path);

	if(bind(s_sock, (struct sockaddr*)&ser, len)) {
		perror("bind");
		exit(1);
	}

	if(listen(s_sock, 5) < 0) {
		perror("listen");
		exit(1);
	}

	printf("Waiting for Accept...\n");
	if((a_sock = accept(s_sock, (struct sockaddr*)&cli, &clen)) == -1) {
		perror("accept");
		exit(1);
	}
	printf("Connect with Client!\n");

	while(1) {
		memset(r_buf, '\0', sizeof(r_buf));
		memset(s_buf, '\0', sizeof(s_buf));

		if(recv(a_sock, r_buf, sizeof(r_buf), 0) == -1) {
			perror("recv");
			exit(1);
		}

		if(strcmp("exit", r_buf) == 0)
			break;

		if((fd = open(r_buf, O_RDONLY)) == -1) {
			strcpy(s_buf, "File not exist!!"); 
		}else {
			if((n = read(fd, s_buf, BYTE)) > 0) {
			}	
			close(fd);
		}
	
		if(send(a_sock, s_buf, sizeof(s_buf), 0) == -1) {
			perror("send");
			exit(1);
		}
	}

	close(a_sock);
	close(s_sock);
	return 0;
}
