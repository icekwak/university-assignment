#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	char path[1024];
	DIR *dirp;
	struct dirent *dentry;
	int dirCnt = 0, fileCnt = 0;

	printf("path: ");
	scanf("%s", path);

	if((dirp = opendir(path)) == NULL)
		exit(1);

	while(dentry = readdir(dirp))
	{
		if(dentry->d_type == DT_DIR)
			dirCnt++;
		else
			fileCnt++;
	}

	printf("--[%s]경로의 dir개수와 file개수--\n", path);
	printf("dir_count: %d\n", dirCnt);
	printf("file_count: %d\n", fileCnt);

	closedir(dirp);
}
