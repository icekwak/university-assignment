#include <unistd.h>

main()
{
	char *envlist[] = {"APPLE=0", "BANANA=1", (char *)0};

	execle("ex09-13", "ex09-13", (char *)0, envlist);
}
