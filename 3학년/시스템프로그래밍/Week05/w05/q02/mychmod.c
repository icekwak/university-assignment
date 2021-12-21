#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>

char* getPermission(char* filename);
void setPermission(char* filename, char* permission);

int main(int argc, char* argv[]) {
	char* filename;
	char* permission;

	// check if first argument is a permission number
	int check = 0;
	if(isdigit(argv[1][0]) != 0) {
		permission = argv[1];
		filename = argv[2];
		check = 1;
	} else
		filename = argv[1];

	// chmod
	if(check == 0) {
		printf("Permission: %s\n", getPermission(filename));
	}
	else {
		printf("permission (before): %s\n", getPermission(filename));
		setPermission(filename, permission);
		printf("permission (after): %s\n", getPermission(filename));
	}
				
	return 0;
}

char* getPermission(char* filename) {
	int shift = 0;
	char* str_per = (char*)malloc(sizeof(char) * 10);
	struct stat buf;
	
	stat(filename, &buf);
	
	while(shift == 0 || shift == 3 || shift == 6) {
		if((buf.st_mode & (S_IREAD >> shift)) != 0)
			str_per[shift] = 'r';
		else
			str_per[shift] = '-';

		if((buf.st_mode & (S_IWRITE >> shift)) != 0)
			str_per[shift+1] = 'w';
		else
			str_per[shift+1] = '-';

		if((buf.st_mode & (S_IEXEC >> shift)) != 0)
			str_per[shift+2] = 'x';
		else
			str_per[shift+2] = '-';

		shift += 3;
	}

	return str_per;
}

void setPermission(char* filename, char* permission) {
	int i = 0;
	int int_per = 0;
	struct stat buf;

	stat(filename, &buf);

	for(i; i<3; i++) {
		int_per = permission[i] - '0';
				
		// permission reset
		if(i == 0)
			buf.st_mode &= ~(S_IRWXU);
		else if(i == 1)
			buf.st_mode &= ~(S_IRWXG);
		else
			buf.st_mode &= ~(S_IRWXO);

		// read
		if(int_per >= 4) {	
			if(i == 0)
				buf.st_mode |= S_IRUSR;
			else if(i == 1)
				buf.st_mode |= S_IRGRP;
			else
				buf.st_mode |= S_IROTH;
			int_per -= 4;
		}

		// write
		if(int_per >= 2) {	
			if(i == 0)
				buf.st_mode |= S_IWUSR;
			else if(i == 1)
				buf.st_mode |= S_IWGRP;
			else
				buf.st_mode |= S_IWOTH;
			int_per -= 2;
		}

		// execute
		if(int_per == 1) {	
			if(i == 0)
				buf.st_mode |= S_IXUSR;
			else if(i == 1)
				buf.st_mode |= S_IXGRP;
			else
				buf.st_mode |= S_IXOTH;
		}
	}

	chmod(filename, buf.st_mode);
}

