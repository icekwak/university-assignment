#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void handler(int signo) {
	printf("SIGQUIT handler is called!\n");
	psignal(signo, "Received Signal");
}

int main() {
	void (*hand)(int);

	hand = signal(SIGQUIT, handler);
	if(hand == SIG_ERR) {
		perror("signal");
		exit(1);
	}
	
	printf("wait input [ctrl + \\].. \n");
	pause();

	return 0;
}
