#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void handler(int signo) {
	sigset_t st;

	sigfillset(&st);
        sigdelset(&st, SIGINT);
	sigprocmask(SIG_BLOCK, &st, (sigset_t *)NULL);

	printf("At handler : Wake up!\n");
}

int main() {
	signal(SIGALRM, handler);

	for(int i=0; i<5; i++) {
		alarm(2);
		printf("Pause ...\n");
		pause();
	}


	printf("Bye~\n");
	return 0;
}
