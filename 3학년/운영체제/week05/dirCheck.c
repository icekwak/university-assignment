#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>

int main()
{
	DIR *dirp;
	struct dirent *dentry;

	if((dirp = opendir(".")) == NULL)
		exit(1);

	while(dentry = readdir(dirp))
	{
		printf("%s\n", dentry->d_name);
		if(dentry->d_type == DT_DIR)
		{
			printf("디렉터리입니다.\n");
		}
		else
		{
			printf("디렉터리가 아닙니다.\n");
		}
	}

	closedir(dirp);
}
