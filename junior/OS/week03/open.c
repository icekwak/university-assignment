#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd;
	char *str = "Hello, world!";

	fd = open("./task.txt", O_RDWR);
	write(fd, str, strlen(str));

	close(fd);
}
