#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
	char *filename = argv[1];
	struct stat buf;
	int kind;
	char *file_type;
	char mode[10];
	char per_num[4];
	int per_start;

	stat(filename, &buf);

	printf("Filename: %s\n", filename);
	printf("- inode number: %d\n", (int)buf.st_ino);

	kind = buf.st_mode & S_IFMT;
	switch(kind) {
		case S_IFDIR:
			file_type = "Directory";
			break;
		case S_IFREG:
			file_type = "Regular File";
			break;
		case S_IFIFO:
			file_type = "FIFO";
			break;
		case S_IFLNK:
			file_type = "Symbolic Link File";
			break;
		case S_IFSOCK:
			file_type = "Socket File";
		case S_IFCHR:
		case S_IFBLK:
			file_type = "Device Special File";
			break;
		default:
			file_type = "";
			break;
	}	
	printf("- File type: %s\n", file_type);

	sprintf(mode, "%o", (unsigned int)buf.st_mode);
	mode[strlen(mode)] = '\0';
	per_start = strlen(mode) - 3;
	
	int i = 0;
	for(i; i<3; i++) {
		per_num[i] = mode[per_start + i];
	}
	per_num[3] = '\0';
	printf("- Permisstion: %s\n", per_num);
	
	printf("- Number of links: %o\n", (unsigned int)buf.st_nlink);
	printf("- Size: %d\n", (int)buf.st_size);

	return 0;
}
