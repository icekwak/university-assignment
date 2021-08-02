#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
int pathCheck(char *path);

int main()
{
	char path[1024];
	
	printf("path: ");
	scanf("%s", path);

	if(pathCheck(path) == 0)
		printf("[%s] 경로 존재\n", path);
	else
		printf("[%s] 경로 미존재\n", path);
}

int pathCheck(char *path)
{
	DIR *dirp;
	int r;

	if((dirp = opendir(path)) != NULL)
		r = 0;
	else
		r = -1;

	closedir(dirp);
	return r;
}
