#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define PORTNUM 9003

int main() {
	char send_buf[BUFSIZ];
	char recv_buf[BUFSIZ];
	struct sockaddr_in svr_sin, clt_sin;
	int svr_sock, clt_sock;
	int clt_len = sizeof(clt_sin);
	int clt_cnt = 0;

	if((svr_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("socker");
		exit(1);
	}

	memset((char*)&svr_sin, '\0', sizeof(svr_sin));
	svr_sin.sin_family = AF_INET;
	svr_sin.sin_port = htons(PORTNUM);
	svr_sin.sin_addr.s_addr = inet_addr("127.0.0.1");

	if(bind(svr_sock, (struct sockaddr*)&svr_sin, sizeof(svr_sin))) {
		perror("bind");
		exit(1);
	}

	if(listen(svr_sock, 5)) {
		perror("listen");
		exit(1);
	}

	while(1) {
		if((clt_sock = accept(svr_sock, (struct sockaddr*)&clt_sin, &clt_len)) == -1) {
			perror("accept");
			exit(1);
		}

		clt_cnt++;
		printf("Client[%d] Connect\n", clt_cnt);

		switch(fork()) {
			case 0:
				close(svr_sock);
				while(1) {
					memset(recv_buf, '\0', sizeof(recv_buf));

					if(recv(clt_sock, recv_buf, sizeof(recv_buf), 0) == -1) {
						perror("recv");
						exit(1);
					}

					printf("Client[%d]: %s\n", clt_cnt, recv_buf);

					if(send(clt_sock, recv_buf, strlen(recv_buf)+1, 0) == -1) {
						perror("send");
						exit(1);
					}

					if(strcmp(recv_buf, "<QUIT>") == 0) {
						printf("Client[%d] exit\n", clt_cnt);
						break;
					}
				}
				exit(0);
		}
		close(clt_sock);
	}
	return 0;
}
