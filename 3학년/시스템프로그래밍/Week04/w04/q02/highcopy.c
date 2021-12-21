#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
	if(argc != 3 && argc != 5) { 
		printf("./highcopy <src_filename> <dst_filename>\n");
		printf("./highcopy -c <byte> <src_filename> <dst_filename>\n");
		exit(1);
	}

	extern char *optarg;
 	extern int optind;
	int option;

	char *src_filename = NULL;
 	char *dst_filename = NULL;
	FILE *rfp, *wfp;
	int c = 0;
	int byte = 0; // argument of option -c 

	// option
	while((option = getopt(argc, argv, "d:")) != -1) {
		switch(option) {
			case 'd':
				if(isdigit(*optarg) == 0) {
					printf("-d <byte> : 'byte' is a number \n");
					exit(1);
				}
				byte = atoi(optarg);
				break;
			default:
				printf("./lowcopy: valid option -- 'd'\n");
				exit(1);
				break;
		}
	}

	src_filename = argv[optind];
	dst_filename = argv[optind + 1];

	rfp = fopen(src_filename, "r");
	if(rfp == NULL) {
		printf("failed to open %s\n", src_filename);
		exit(1);
	}

	wfp = fopen(dst_filename, "w");
	if(wfp == NULL) {
		printf("failed to open %s\n", dst_filename);
		exit(1);
	}

	// file copy
	while((c = fgetc(rfp)) != EOF) {
		if(c != '\0' && c != '\n')
			c -= (char) byte;
		fputc(c, wfp);
	}

	fclose(rfp);
	fclose(wfp);
	return 0;
}
