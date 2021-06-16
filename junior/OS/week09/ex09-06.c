#include <sys/types.h>
#include <unistd.h>

main()
{
	printf("[ex09-06.c] PPID:%d, PID:%d\n", getppid(), getpid());
}
