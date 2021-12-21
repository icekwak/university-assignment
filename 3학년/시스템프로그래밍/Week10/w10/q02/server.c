#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define PORTNUM 9001

int main() {
	char send_buf[256];
	char recv_buf[256];
	struct sockaddr_in svr_sin, clt_sin;
	int svr_sock;
	int clt_len = sizeof(clt_sin);
	time_t now;

	if((svr_sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
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
	
	while(1) {
		memset(send_buf, '\0', sizeof(send_buf));
		memset(recv_buf, '\0', sizeof(recv_buf));

		if((recvfrom(svr_sock, recv_buf, 255, 0, (struct sockaddr*)&clt_sin, &clt_len)) == -1) {
			perror("recvfrom");
			exit(1);
		}
		printf("Client IP: %s\n", inet_ntoa(clt_sin.sin_addr));
		
		time(&now);
		sprintf(send_buf, "%s", ctime(&now));

		if((sendto(svr_sock, send_buf, strlen(send_buf)+1, 0, (struct sockaddr*)&clt_sin, sizeof(clt_sin))) == -1) {
			perror("sendto");
			exit(1);
		}
	}

	close(svr_sock);
	return 0;
}
