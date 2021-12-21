#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
	if(argc != 2) {
		printf("[help] ./sleepFor <seconde>\n");
		exit(EXIT_FAILURE);
	}
	
	int sec = atoi(argv[1]);

	sleep(sec);

	return 0;
}
