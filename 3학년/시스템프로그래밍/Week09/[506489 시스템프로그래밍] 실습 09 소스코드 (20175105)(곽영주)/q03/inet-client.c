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
	int c_sock;
	char s_buf[SIZE];
	char r_buf[SIZE];
	struct sockaddr_in sin;

	if((c_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("socket");
		exit(1);
	}

	memset((char*)&sin, '\0', sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(PORT);
	sin.sin_addr.s_addr = inet_addr("127.0.0.1");

	if(connect(c_sock, (struct sockaddr*)&sin, sizeof(sin))) {
		perror("connect");
		exit(1);
	}
	
	while(1) {
		memset(s_buf, '\0', sizeof(s_buf));
		memset(r_buf, '\0', sizeof(r_buf));

		printf("===============================================\n");
		printf("Enter to Text: ");
	        gets(s_buf);

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

		printf("%s\n", r_buf);
	}

	close(c_sock);
	return 0;
}
