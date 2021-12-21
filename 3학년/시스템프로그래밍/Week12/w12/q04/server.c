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

void handler(int dumy) { ; }

int main() {
        key_t key;
        int shmid;
        void *shmaddr;
        char buf[BUFSIZE];
	sigset_t mask;
	char file[BUFSIZE][BUFSIZE];
        char *temp;
	int fd, fn;
	int i;

        key = ftok("shmfile", 1);

	// 공유메모리 생성
        shmid = shmget(key, BUFSIZE, IPC_CREAT|0666);

	// 시그널 설정
	sigfillset(&mask);
	sigdelset(&mask, SIGUSR1);

	while(1) {
		memset(buf, '\0', BUFSIZE);
		memset(file[0], '\0', sizeof(file[0]));
		memset(file[0], '\0', sizeof(file[1]));
	
		// 시그널 수신
		sigset(SIGUSR1, handler);
		printf("Server wait for Talker...\n");
		sigsuspend(&mask);

		// 클라이언트 메시지 수신
		shmaddr = shmat(shmid, NULL, 0);
		strcpy(buf, shmaddr);

		// <DOWNLOAD> 문자열 추출
                temp = strtok(buf, " ");
                i = 0;
                while(temp != NULL) {
                        strcpy(file[i], temp);
                        temp = strtok(NULL, " ");
			i++;
                }

		printf("[YOU]: %s\n", buf);

                memset(buf, '\0', BUFSIZE);

		// 다운로드
                if(strcmp(file[0], "<DOWNLOAD>") == 0) {

                        if((fd = open("hello.file", O_RDONLY)) == -1) {
                                perror("open");
                                exit(1);
                        }

			if((fn = read(fd, buf, BUFSIZ)) == -1) {
				perror("read");
				exit(1);
			}
			
			strcpy(shmaddr, buf);
			
			close(fd);
                }
		else {
			// 클라이언트로 메시지 전송
			printf("[ME]: ");
			gets(buf);
			strcpy(shmaddr, buf);
		}
		sleep(1);
		shmdt(shmaddr);
	}
        return 0;
}
