#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
	if(argc != 2) {
		printf("[help] ./randomFork <probability>\n");
		exit(EXIT_FAILURE);
	}

	double prob = atof(argv[1]);
	pid_t pid;
	pid_t wait_pid;
	int status;

	printf("Prob = %f\n", prob);
	srand(time(0));

	while(rand()%9+1 <= (int)(prob * 10)) {
		pid = fork();
		printf("My PID (%d), My Parent PID (%d)\n", getpid(), getppid());

		if(pid > 0) {
			wait_pid = wait(&status);
			printf("Waited pid: %d\n", wait_pid);	
		}	
	}

	return 0;
}
