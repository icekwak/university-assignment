#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[]) {
	int fd, i, k;
	pid_t pid;
	caddr_t addr;
	struct stat statbuf;
	
	if(argc != 2) {
		fprintf(stderr, "Usage : %s filename\n", argv[0]);
		exit(1);
	}

	if(stat(argv[1], &statbuf) == -1) {
		perror("stat");
		exit(1);
	}

	if((fd = open(argv[1], O_RDWR)) == -1) {
		perror("open");
		exit(1);
	}

	addr = mmap(NULL, statbuf.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, (off_t)0);
	if(addr == MAP_FAILED) {
		perror("mmap");
		exit(1);
	}
	close(fd);

	switch(pid = fork()) {
		case -1 :
			perror("fork");
			exit(1);
			break;
		case 0 :
			srand(time(NULL));
			for(i=0; i<100; i++) {
				//k = rand() % 100;
				addr[i] = 'c';
				sleep(1);
			}
			break;
		default :
			sleep(1);
			srand(time(NULL));
			for(i=0; i<100; i++) {
                                k = rand() % 100;
                                addr[k] = 'p';
                                sleep(1);
                        }
			break;
	}

	return 0;
}
