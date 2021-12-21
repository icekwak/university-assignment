#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 19000
#define SIZE 256

int main() {
	struct sockaddr_in sin, cli;
	int s_sock, a_sock;
	int clientlen = sizeof(cli);
	char* s_buf = "Server received the message";
	char r_buf[SIZE];

	if((s_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("socket");
		exit(1);
	}

	memset((char*)&sin, '\0', sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(PORT);
	sin.sin_addr.s_addr = inet_addr("127.0.0.1");

	if(bind(s_sock, (struct sockaddr*)&sin, sizeof(sin))) {
		perror("bind");
		exit(1);
	}

	if(listen(s_sock, 5) < 0) {
		perror("listen");
		exit(1);
	}

	printf("Waiting for Accept...\n");
        if((a_sock = accept(s_sock, (struct sockaddr*)&cli, &clientlen)) == -1) {
               	perror("accept");
                exit(1);
        }

	printf("Connect with Client!\n");
	printf("======================\n");
	while(1) {
		memset(r_buf, '\0', sizeof(r_buf));
		
		if(recv(a_sock, r_buf, sizeof(r_buf), 0) == -1) {
                	perror("recv");
                	exit(1);
       	 	}
        	
		printf("%s\n", r_buf);
	
		if(strcmp("exit", r_buf) == 0)
                        break;

        	if(send(a_sock, s_buf, strlen(s_buf)+1, 0) == -1) {
                	perror("send");
        	        exit(1);
	        }
	}

	close(a_sock);
	close(s_sock);
	return 0;
}
