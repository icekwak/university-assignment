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
        struct sockaddr_in cli_sin;
        int cli_sock;
	char buf[BUFSIZE];
	char down_name[BUFSIZE] = "./download_";
	int pd, pn;
	int fd, fn;

        if((cli_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
                perror("socket");
                exit(1);
        }

        memset((char *)&cli_sin, '\0', sizeof(cli_sin));
        cli_sin.sin_family = AF_INET;
        cli_sin.sin_port = htons(PORT);
        cli_sin.sin_addr.s_addr = inet_addr(IP);

	if(connect(cli_sock, (struct sockaddr *)&cli_sin, sizeof(cli_sin))) {
		perror("connect");
		exit(1);
	}

	// 다운로드
	printf("=== [CONNECT] ===\n");
	while(1) {
		memset(buf, '\0', BUFSIZE);
		
		printf("filename: ");
		gets(buf);

		// 파일명 전송
		if(send(cli_sock, buf, strlen(buf)+1, 0) == -1) {
			perror("send filename");
			exit(1);
		}

		// 종료
		if(strcmp(buf, "<EXIT>") == 0) {
			printf("Exit\n");
			break;
		}

		memset(buf, '\0', BUFSIZE);

		// 다운로드 성공여부 메시지 수신
		if(recv(cli_sock, buf, sizeof(buf), 0) == -1) {
			perror("recv download msg");
			exit(1);
		}

		if(strcmp(buf, "FAIL") == 0) {
			printf("File does not exist\n");
		}else {
			// 다운로드 파일명
			strcat(down_name, buf);
			printf("Download: %s\n", down_name);

			memset(buf, '\0', BUFSIZE);

			// 파이프 열기
			if((pd = open(FIFONAME, O_RDONLY)) == -1) {
				perror("open fifo");
				exit(1);
			}

			if((pn = read(pd, buf, BUFSIZE)) == -1) {
				perror("read fifo");
				exit(1);
			}
			printf("file content: %s\n", buf);

			close(pd);

			// 파일 저장
			if((fd = open(down_name, O_CREAT | O_WRONLY, 0644)) == -1) {
				perror("open file");
				exit(1);
			}

			if((fn = write(fd, buf, strlen(buf)+1)) == -1) {
				perror("write file");
				exit(1);
			}

			close(fd);
		}
	}

	close(cli_sock);
        return 0;
}

