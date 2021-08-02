#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int grgc, char **argv)
{
	pid_t pid;
	
	pid = fork();

	if(pid >  0)
	{
		execl("/bin/cat", "cat", argv[1], (char *)0);
		printf("fail to parent-execlp\n");
	}	
	else if(pid == 0)
	{
		execl("/bin/cat", "cat", argv[2], (char *)0);
		printf("fail to child-execlp\n");
	}
	else
	{
		printf("fail to fork()\n");
	}

	return 0;
}
