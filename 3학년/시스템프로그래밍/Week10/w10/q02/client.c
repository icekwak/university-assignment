#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define PORTNUM 9001

int main() {
	struct sockaddr_in clt_sin;
	int clt_sock, n;
	char* send_buf = "TIME_REQUEST";
	char recv_buf[256];

	if((clt_sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
		perror("socket");
		exit(1);
	}

	memset((char*)&clt_sin, '\0', sizeof(clt_sin));
	clt_sin.sin_family = AF_INET;
	clt_sin.sin_port = htons(PORTNUM);
	clt_sin.sin_addr.s_addr = inet_addr("127.0.0.1");

	if(sendto(clt_sock, send_buf, strlen(send_buf)+1, 0, (struct sockaddr*)&clt_sin, sizeof(clt_sin)) == -1) {
		perror("sendto");
		exit(1);
	}
	
	n = recvfrom(clt_sock, recv_buf, 255, 0, NULL, NULL);
	recv_buf[n] = '\0';

	printf("Server Time: %s", recv_buf);

	close(clt_sock);
	return 0;
}
