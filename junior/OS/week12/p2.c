#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define PIPESIZE 500

int main()
{
	int p[2];
	int pfd, cfd;
	char pstr[PIPESIZE];
	char cstr[PIPESIZE];
	pid_t pid;
	off_t fileSize, posi;
	fd_set initset, newset;

	if(pipe(p) == -1)
	{
		printf("fail to call pipe()\n");
		exit(1);
	}

	if((pid = fork()) == -1)
	{
		printf("fail to call fork()\n");
		exit(1);
	}
	else if(pid > 0)
	{
		close(p[0]);

		pfd = open("a.txt", O_RDONLY);
		if(pfd == -1)
		{
			printf("fail to open('a.txt')\n");
			exit(1);
		}

		fileSize = lseek(pfd, (off_t)-1, SEEK_END);
		printf("a.txt file size: %d\n", fileSize);

		posi = lseek(pfd, (off_t)0, SEEK_SET);
		while(posi !=  -1)
		{
			if(read(pfd, pstr, PIPESIZE) > 0)
			{
				if(write(p[1], pstr, PIPESIZE) == PIPESIZE)
				{
					sleep(1);
					posi = lseek(pfd, (off_t)(PIPESIZE/256), SEEK_CUR);
					sleep(1);
					continue;
				}
				printf("[parent] fail to call write()\n");
				exit(1);
			}
			printf("[parent] exit read\n");
			exit(1);
		}
		close(pfd);
		exit(1);
	}
	else
	{
		close(p[1]);
		
		FD_ZERO(&initset);
		FD_SET(p[0], &initset);
		
		newset = initset;
		while(select(p[0] + 1, &newset, NULL, NULL, NULL) > 0)
		{
			if(FD_ISSET(p[0], &newset))
			{
				if(read(p[0], cstr, PIPESIZE) > 0)
				{
					cfd = open("b.txt", O_WRONLY);
					if(cfd == -1)
					{
						printf("fail to open('b.txt')\n");
						exit(1);
					}
					
					lseek(cfd, (off_t)0, SEEK_END);
					
					write(cfd, cstr, PIPESIZE);
					
					close(cfd);
				}
			}
			newset = initset;
		}
	}
}
