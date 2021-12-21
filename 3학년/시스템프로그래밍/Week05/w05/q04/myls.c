#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>

int main() {
	DIR* dp;
	struct dirent* dent;
	char file_list[10][50];
	char dir_list[10][50];
	int file_n = 0;	
	int dir_n = 0;
	int i;

	// opendir
	if((dp = opendir(".")) == NULL) {
		perror("failed to opendir");
		exit(1);
	}

	// readdir
	while((dent = readdir(dp))) {
		if(dent->d_name[0] == '.')
			continue;

		if(!strcmp(dent->d_name, "myls") || !strcmp(dent->d_name, "myls.c"))
			continue;

		if(dent->d_type == 8) { // file
			strcpy(file_list[file_n], dent->d_name);
			file_n++;
		}
		else { // dir: 4
			strcpy(dir_list[dir_n], dent->d_name);
			dir_n++;
		}
	}

	printf("<Regular Files>\n");
	for(i=0; i<file_n; i++)
		printf("%s\n", file_list[i]);
	
	printf("\n<Directories>\n");
	for(i=0; i<dir_n; i++)
		printf("%s\n", dir_list[i]);

	closedir(dp);
	return 0;
}
