#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	char *filename = "a.txt";
	char *softfilename = "b.txt";
	int fd;

	fd = open(filename, O_RDWR | O_CREAT, 0755);
	close(fd);

	symlink(filename, softfilename);
}
