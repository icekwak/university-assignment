#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	char* dir = argv[1];
	FILE* fp;

	// mkdir
	if(mkdir(dir, 0755) == -1) {
		perror("failed to mkdir");
		exit(1);
	}

	chdir(dir);
	
	// file create
	if((fp = fopen("README.txt", "w")) == NULL) {
		perror("failed to fopen");
		exit(1);
	}

	fclose(fp);
	return 0;
}
