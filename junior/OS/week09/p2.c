#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

main()
{
	pid_t pid;
	int filedes;
	ssize_t n;
	time_t t;
	char *strTime;

	pid = fork();
	if(pid > 0)
	{
		exit(0);
	}
	else if(pid == 0)
	{
		while(1)
		{
			filedes = open("curtime.txt", O_WRONLY);
			if(filedes == -1)
			{
				printf("file open error\n");
				exit(0);
			}
			else
			{
				time(&t);
				strTime = ctime(&t);
				
				n = write(filedes, strTime, strlen(strTime));
				if(n != strlen(strTime))
				{
					printf("file write error\n");
					close(filedes);
					exit(0);
				}				
				close(filedes);
				sleep(10);
			}
		}
	}
	else
		printf("fail to fork\n");
}
