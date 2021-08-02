#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
void entryList(char *path, int n);

int main()
{
	char *path = "hw03";
	
	entryList(path, 0);
}

void entryList(char *path, int n)
{
	DIR *dirp;
	struct dirent *dentry;

	if((dirp = opendir(path)) == NULL)
		exit(1);

	chdir(path);
	while(dentry = readdir(dirp))
	{
		char *name = dentry->d_name;
		int i;
		if(dentry->d_type == DT_DIR)
		{
			if(strcmp(name, ".") != 0 && strcmp(name, "..") != 0)
			{
				for(i=0; i<n; i++)
					printf(" ");
				printf("[%s]\n", name);
				entryList(name, n+1);
				chdir("..");
			}
			else
				continue;
		}
		else
		{
			for(i=0; i<n; i++)
				printf(" ");
			printf("-%s\n", name);
		}
	}

	closedir(dirp);
}
