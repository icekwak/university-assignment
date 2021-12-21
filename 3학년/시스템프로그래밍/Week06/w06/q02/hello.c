#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main() {
	printf("Hello world begins\n");
	
	srand(time(NULL));
	int n = (rand() % 21) + 10;
	sleep(n);

	printf("Hello world ends\n");

	return 0;
}
