#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	sigset_t st;

	if(sigfillset(&st) == -1) {
		perror("sigfillset");
		exit(1);
	}
	printf("Add all signal..\n");

	if(sigismember(&st, SIGBUS) == 1) {
		printf("SIGBUS is set.\n");
	}else {
		printf("SIGBUS is not set.\n");
	}

	return 0;
}
