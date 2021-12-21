#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void handler(int signo) {
	printf("Nice to meet you!\n");
}

int main() {
	struct itimerval it;
	
	sigset(SIGALRM, handler);

	it.it_value.tv_sec = 1;
        it.it_value.tv_usec = 0;
	it.it_interval.tv_sec = 1;
	it.it_interval.tv_usec = 0;

	if(setitimer(ITIMER_REAL, &it, (struct itimerval *)NULL) == -1) {
		perror("setitimer");
		exit(1);
	}

	while(1) {
		//if(getitimer(ITIMER_REAL, &it) == -1) {
		//	perror("getitimer");
		//	exit(1);
		//}
		//alarm(1);
		//printf("wait..\n");
		pause();
	}

	return 0;
}
