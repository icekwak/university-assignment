#include <sys/types.h>
#include <unistd.h>

main()
{
	pid_t pid;

	if((pid = fork()) > 0)
	{
		printf("[ex09-05.c] PPID:%d, PID:%d\n", getppid(), getpid());
		sleep(1);
	}
	else if(pid == 0)
	{
		printf("[ex09-05.c] PPID:%d, PID:%d\n", getppid(), getpid());
		execl("ex09-06", "ex09-06", (char *)0);
	}
	else
		printf("fail to fork\n");
}
