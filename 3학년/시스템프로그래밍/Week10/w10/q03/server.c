#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORTNUM 9002
#define IP "127.0.0.1"
#define MESSAGE "<Available Services>\n1. Echo server <ECHO>\n2. Get server info <SINFO>\n3. Get server time <STIME>"

int main() {
	char send_buf[BUFSIZ];
	char recv_buf[BUFSIZ];
	struct sockaddr_in svr_sin, clt_sin;
	int svr_sock, clt_sock;
	int clt_len = sizeof(clt_sin);
	time_t now;
	struct hostent *hp;

	if((svr_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("socker");
		exit(1);
	}

	memset((char*)&svr_sin, '\0', sizeof(svr_sin));
	svr_sin.sin_family = AF_INET;
	svr_sin.sin_port = htons(PORTNUM);
	svr_sin.sin_addr.s_addr = inet_addr(IP);

	if(bind(svr_sock, (struct sockaddr*)&svr_sin, sizeof(svr_sin))) {
		perror("bind");
		exit(1);
	}

	if(listen(svr_sock, 5)) {
		perror("listen");
		exit(1);
	}

	if((clt_sock = accept(svr_sock, (struct sockaddr*)&clt_sin, &clt_len)) == -1) {
		perror("accept");
		exit(1);
	}
	
	sprintf(send_buf, "%s", MESSAGE);
	if(send(clt_sock, send_buf, strlen(send_buf)+1, 0) == -1) {
		perror("send of message");
		exit(1);
	}
	memset(send_buf, '\0', sizeof(send_buf));

	if(recv(clt_sock, recv_buf, sizeof(recv_buf), 0) == -1) {
		perror("recv of menu");
		exit(1);
	}

	if(strcmp(recv_buf, "<ECHO>") == 0) {
		printf("<ECHO>\n");
		while(1) {
			memset(recv_buf, '\0', sizeof(recv_buf));
			if(recv(clt_sock, recv_buf, sizeof(recv_buf), 0) == -1) {
				perror("recv of <ECHO>");
				exit(1);
			}
			printf("RECV: %s\n", recv_buf);

			if(send(clt_sock, recv_buf, strlen(recv_buf)+1, 0) == -1) {
				perror("send of <ECHO>");
				exit(1);
			}

			if(strcmp(recv_buf, "<QUIT>") == 0)
				break;
		}	
	}
	else if (strcmp(recv_buf, "<SINFO>") == 0) {
		printf("<SINFO>\n");
		hp = gethostbyaddr(&svr_sin.sin_addr, sizeof(svr_sin.sin_addr), AF_INET);
		sprintf(send_buf, "hostname: %s\nIP: %s\nPort: %d\n", hp->h_name, IP, PORTNUM);
		if(send(clt_sock, send_buf, strlen(send_buf)+1, 0) == -1) {
			perror("send of <SINFO>");
			exit(1);
		}
	}
	else if (strcmp(recv_buf, "<STIME>") == 0) {
		printf("<STIME>\n");
		time(&now);
		sprintf(send_buf, "Server time: %s", ctime(&now));
		if(send(clt_sock, send_buf, strlen(send_buf)+1, 0) == -1) {
			perror("send of <STIME>");
			exit(1);
		}
	}
	else printf("Not menu\n");

	close(clt_sock);
	close(svr_sock);

	return 0;
}
