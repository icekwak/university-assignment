#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd;
	off_t p;

	fd = open("task.txt", O_RDWR);

	p = lseek(fd, (off_t)20, SEEK_END);
	printf("pointer : %d\n", p);

	close(fd);
	return 0;
}
