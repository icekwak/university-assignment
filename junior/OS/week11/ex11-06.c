#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

void sigintHandler(int signum);

main()
{
	pid_t pid;
	int count = 5;
	int sum = 0;
	struct sigaction act;

	sigfillset(&(act.sa_mask));
	act.sa_handler = sigintHandler;
	sigaction(SIGINT, &act, NULL);

	pid = fork();
	if(pid > 0)
	{
		pause();
		printf("parent bye!\n");
	}
	else if(pid == 0)
	{
		while(count > 0)
		{
			sum += count;
			count--;
		}
		printf("1부처 5까지 더한 결과 = %d\n", sum);
		
		printf("child bye!\n");
		
		kill(getppid(), SIGINT);
		raise(SIGINT);
	}
	else
		printf("fail to fork\n");
}
void sigintHandler(int signum){}
