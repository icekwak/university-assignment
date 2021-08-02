#include <unistd.h>
#include <stdlib.h>

main()
{
	putenv("APPLE=BANANA");
	printf("%s\n", getenv("APPLE"));

	execl("ex09-11", "ex09-11", (char *)0);
}
