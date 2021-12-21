#include <stdio.h>
#include <getopt.h>

int main(int argc, char *argv[]) {
	int n;
	extern char *optarg;

	if(argc == 1) {
		printf("ERROR: please provide at least one option\n");
		return 0;
	}

	while((n = getopt(argc, argv, "au:h")) != -1) {
		switch(n) {
			case 'a':
				printf("Welcome to System Programming (2021-2)\n");
				break;
			case 'u':
				printf("Nice to meet you, %s\n", optarg);
				break;
			case 'h':
				printf("-a : Welcome to System Programming (2021-2)\n");
				printf("-u (arg) : Nice to meet you, (arg)\n");
				printf("-h : help\n");
				break;
			default:
				printf("non-existent argument\n");
				break;
		}
	}
	return 0;
}
