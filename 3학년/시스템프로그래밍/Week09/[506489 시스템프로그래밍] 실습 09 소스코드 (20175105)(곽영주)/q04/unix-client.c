#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/un.h>

#define SOCKET_NAME "q04_socket"
#define SIZE 256

int main() {
	struct sockaddr_un ser;
	int c_sock;
	int len;
	char s_buf[SIZE];
	char r_buf[SIZE];

	if((c_sock = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
		perror("socket");
		exit(1);
	}

	memset((char*)&ser, '\0', sizeof(ser));
	ser.sun_family = AF_UNIX;
	strcpy(ser.sun_path, SOCKET_NAME);
	len = sizeof(ser.sun_family) + strlen(ser.sun_path);

	if(connect(c_sock, (struct sockaddr*)&ser, len) < 0) {
		perror("connect");
		exit(1);
	}

	while(1) {
		memset(r_buf, '\0', sizeof(r_buf));
                memset(s_buf, '\0', sizeof(s_buf));

		printf("===========\n");
		printf("Enter to absolute path the file: ");
		scanf("%s", s_buf);

		if(send(c_sock, s_buf, sizeof(s_buf), 0) == -1) {
			perror("send");
			exit(1);
		}
		
		if(strcmp("exit", s_buf) == 0)
			break;

		if(recv(c_sock, r_buf, sizeof(r_buf), 0) == -1) {
			perror("recv");
			exit(1);
		}

		printf("result: %s\n", r_buf);
	}

	close(c_sock);
	return 0;
}
