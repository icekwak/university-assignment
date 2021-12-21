#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define PORTNUM 9003

int main() {
	struct sockaddr_in clt_sin;
	int clt_sock;
	char send_buf[BUFSIZ];
	char recv_buf[BUFSIZ];

	if((clt_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("socket");
		exit(1);
	}

	memset((char*)&clt_sin, '\0', sizeof(clt_sin));
	clt_sin.sin_family = AF_INET;
	clt_sin.sin_port = htons(PORTNUM);
	clt_sin.sin_addr.s_addr = inet_addr("127.0.0.1");

	if(connect(clt_sock, (struct sockaddr*)&clt_sin, sizeof(clt_sin))) {
		perror("connect");
		exit(1);
	}

	while(1) {
		memset(send_buf, '\0', sizeof(send_buf));
		memset(recv_buf, '\0', sizeof(recv_buf));

		printf("SEND: ");
		gets(send_buf);

		if(send(clt_sock, send_buf, strlen(send_buf)+1, 0) == -1) {
			perror("send");
			exit(1);
		}

		if(recv(clt_sock, recv_buf, sizeof(recv_buf), 0) == -1) {
			perror("recv");
			exit(1);
		}

		printf("RECV: %s\n", recv_buf);

		if(strcmp(recv_buf, "<QUIT>") == 0)
			break;
	}
	close(clt_sock);
	return 0;
}
