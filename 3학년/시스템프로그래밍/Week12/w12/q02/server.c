#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define PORT 9000
#define IP "127.0.0.1"
#define BUFSIZE 256
#define FIFONAME "./HAN-FIFO"

int main() {
	struct sockaddr_in svr_sin, cli_sin;
	int svr_sock, cli_sock;
	int cli_len = sizeof(cli_sin);
	char buf[BUFSIZE];
	char down_name[BUFSIZE];
	char *filename;
	int fd, pd;
	int fn, pn;

	if((svr_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("socket");
		exit(1);
	}

	memset((char *)&svr_sin, '\0', sizeof(svr_sin));
	svr_sin.sin_family = AF_INET;
	svr_sin.sin_port = htons(PORT);
	svr_sin.sin_addr.s_addr = inet_addr(IP);

	if(bind(svr_sock, (struct sockaddr *)&svr_sin, sizeof(svr_sin))) {
		perror("bind");
		exit(1);
	}

	if(listen(svr_sock, 5)) {
		perror("listen");
		exit(1);
	}

	if((cli_sock = accept(svr_sock, (struct sockaddr *)&cli_sin, &cli_len)) == -1) {
		perror("accept");
		exit(1);
	}

	// 다운로드
	printf("=== [ACCEPT] ===\n");
	while(1){
		memset(buf, '\0', BUFSIZE);

		// 파일명 수신
		if(recv(cli_sock, buf, sizeof(buf), 0) == -1) {
			perror("recv filename");
			exit(1);
		}
		printf("Request: %s\n", buf);

		// 종료
		if(strcmp(buf, "<EXIT>") == 0) {
			printf("Exit\n");
			break;
		}

		// 파일명만 추출
		filename = strtok(buf, " ");
              	while(filename != NULL) {
			strcpy(buf, filename);
			filename = strtok(NULL, " ");
		}
		strcpy(down_name, buf);

		// 해당 파일 찾기
		if((fd = open(buf, O_RDONLY)) == -1) {
			// 파일이 존재하지 않는 경우
			strcpy(buf, "FAIL");

			if(send(cli_sock, buf, strlen(buf)+1, 0) == -1) {
                        	perror("send download fail");
                        	exit(1);
                	}
		}else {
			if(send(cli_sock, buf, strlen(buf)+1, 0) == -1) {
                        	perror("send download success");
                        	exit(1);
                	}

			// 파일이 존재하는 경우
			memset(buf, '\0', BUFSIZE);

			if((fn = read(fd, buf, BUFSIZE)) == -1) {
				perror("read file");
				exit(1);
			}

			close(fd);

			// 파이프 생성
			if(mkfifo(FIFONAME, 0666) == -1) {
				perror("mkfifo");
				exit(1);
			}

			if((pd = open(FIFONAME, O_WRONLY)) == -1) {
				perror("open fifo");
				exit(1);
			}

			if((pn = write(pd, buf, strlen(buf)+1)) == -1) {
				perror("write fifo");
				exit(1);
			}

			close(pd);
		}

		printf("Download: %s\n", buf);
	}

	close(cli_sock);
	close(svr_sock);
	return 0;
}
