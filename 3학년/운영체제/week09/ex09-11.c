#include <unistd.h>
#include <stdlib.h>

main()
{
	printf("%s\n", getenv("APPLE"));
	unsetenv("APPLE");

	if(!getenv("APPLE"))
		printf("APPLE not found\n");
}
