#include <sys/types.h>
#include <signal.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

#define BUFSIZE 128

int main(int argc, char **argv) {
	key_t key;
	int shmid;
	void *shmaddr;
	char buf[BUFSIZE];
	char file[BUFSIZE][BUFSIZE];
	char *temp;
	int fd, fn;
	int i;

	key = ftok("shmfile", 1);

	while(1) {
		memset(buf, '\0', BUFSIZE);
		memset(file[0], '\0', sizeof(file[0]));
                memset(file[0], '\0', sizeof(file[1]));

		// 서버로 메시지 전송(다운로드 시, 앞에 <DOWNLOAD> 입력)
		printf("[ME]: ");
		gets(buf);

		// <DOWNLOAD> 문자열 추출
		temp = strtok(buf, " ");
		i = 0;
		while(temp != NULL) {
			strcpy(file[i], temp);
			temp = strtok(NULL, " ");
			i++;
		}

		// 공유메모리 연결
		shmid = shmget(key, BUFSIZE, 0);
		shmaddr = shmat(shmid, NULL, 0);
		
		// 공유메모리에 쓰기
		strcpy(shmaddr, buf);

		// 다운로드
		if(strcmp(file[0], "<DOWNLOAD>") == 0) {
			if((fd = open("download.file", O_CREAT | O_WRONLY, 0644)) == -1) {
				perror("open");
				exit(1);
			}
		}

		// 시그설 전송
                kill(atoi(argv[1]), SIGUSR1);
                sleep(3);

		// 종료
		if(strcmp(buf, "<EXIT>") == 0) {
			shmdt(shmaddr);
			break;
		}

		memset(buf, '\0', BUFSIZE);

		// 서버 메시지 수신
		strcpy(buf, shmaddr);
		printf("[YOU]: %s\n", buf);

		// 다운로드
		if(strcmp(file[0], "<DOWNLOAD>") == 0) {
			if((fn = write(fd, buf, strlen(buf)+1)) == -1) {
				perror("write");
				exit(1);
			}
			close(fd);
		}

		// 공유메모리 연결 해제
		shmdt(shmaddr);
	}

	return 0;
}
