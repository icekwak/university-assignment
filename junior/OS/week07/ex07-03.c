#include <unistd.h>

main()
{
	printf("before executing ls -l\n");
	exec("/bin/ls", "ls", "-l", (char *)0);
	printf("after executing ls -l\n");
}
