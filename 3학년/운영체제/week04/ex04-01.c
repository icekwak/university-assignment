#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main()
{
	char *originalname = "test.txt";
	char *hardfilename = "test.txt.hard";
	char *softfilename = "test.txt.soft";

	int filedes, retval;
	mode_t oldmask;
	char buffer[1024];
	int nread;
	struct stat finfo;
	oldmask = umask(0377);
	int slink, hlink; // symlink, link return값

	filedes = open(originalname, O_RDWR | O_CREAT, 0755);
	close(filedes);

	if((retval = access(originalname, W_OK)) == -1)
	{
		printf("%s in not writable\n", originalname);
		chmod(originalname, 0644);
	}

	// link 예외처리
	if((hlink = link(originalname, hardfilename)) == -1)
	{
		printf("not hardlink\n");
	}
	else
	{
		rename(hardfilename, "newname.txt");
	}

	// symlink 예외처리
	if((slink = symlink(originalname, softfilename)) == -1)
	{
		printf("not symlink\n");
	}
	else
	{
		nread = readlink(softfilename, buffer, 1024);
		write(1, buffer, nread);
	}
	
	stat(originalname, &finfo);
	printf("\n%s\n", originalname);
	printf("File mode : %o\n", finfo.st_mode);
	printf("Files size : %d\n", finfo.st_size);
	printf("Num of block : %d\n", finfo.st_blocks);
}
