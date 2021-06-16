#include <unistd.h>
#include <signal.h>

main()
{
	static struct sigaction act;
	sigset_t setAll, setSigint;
	int count = 5;

	void int_handle(int);
	act.sa_handler = int_handle;
	sigaction(SIGINT, &act, NULL);

	sigfillset(&setAll);

	sigemptyset(&setSigint);
	sigaddset(&setSigint, SIGINT);

	sigprocmask(SIG_BLOCK, &setAll, NULL);

	while(count)
	{
		printf("don`t disturb me (%d)\n", count--);
		sleep(1);
	}

	sigprocmask(SIG_UNBLOCK, &setSigint, NULL);

	while(1){}
}

void int_handle(int sigmun)
{
	printf("\ndisturb me!\n");
	exit(0);
}
