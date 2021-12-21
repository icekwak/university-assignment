#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	sigset_t st;
	int i;

	sigemptyset(&st);
	sigaddset(&st, SIGINT);

	sigprocmask(SIG_BLOCK, &st, (sigset_t *)NULL);

	for(i=0; i<10; i++) {
		printf("Hallym Software\n");
		sleep(1);
	}

	return 0;
}
