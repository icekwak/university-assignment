#include <stdio.h>
#include <unistd.h>

int main()
{
	char *filename = "a.txt";
	char *hardfilename = "a.txt.hard";
	char buffer[1024];
	int nread;

	link(filename, hardfilename);

	nread = readlink(hardfilename, buffer, 1024);
	write(1, buffer, nread);
}
