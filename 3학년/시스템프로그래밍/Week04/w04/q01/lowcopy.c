#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <fcntl.h>
#include <ctype.h>

#define BUF_SIZE 10
#define N_BYTE 1

int main(int argc, char *argv[]) {
	if(argc != 3 && argc != 5) {
		printf("./lowcopy <src_filename> <dst_filename>\n");	
		printf("./lowcopy -c <byte> <src_filename> <dst_filename>\n");
		exit(1);
	}

	extern char *optarg;
 	extern int optind;
	int option;

	char *src_filename = NULL;
 	char *dst_filename = NULL;
	char buf[BUF_SIZE] = {0,};
	int rfd, wfd;
	int n = 0;
	int byte = 0; // argument of option -c 

	// option
	while((option = getopt(argc, argv, "c:")) != -1) {
		switch(option) {
			case 'c':
				if(isdigit(*optarg) == 0) {
					printf("-c <byte> : 'byte' is a number \n");
					exit(1);
				}
				byte = atoi(optarg);
				break;
			default:
				printf("./lowcopy: valid option -- 'c'\n");
				exit(1);
				break;
		}
	}

	src_filename = argv[optind];
	dst_filename = argv[optind + 1];

	rfd = open(src_filename, O_RDONLY, 0644);
	if(rfd == -1) {
		printf("failed to open %s\n", src_filename);
		exit(1);
	}

	wfd = open(dst_filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if(wfd == -1) {
		printf("failed to open %s\n", dst_filename);
		exit(1);
	}

	// file copy
	while((n = read(rfd, buf, N_BYTE)) > 0) {
		if(isalpha(buf[0]) > 0)
			buf[0] += (char) byte;

		if(write(wfd, buf, n) != n)
			perror("failed to write");
	}

	if(n == -1)
		perror("failed to read");

	close(rfd);
	close(wfd);
	return 0;
}
