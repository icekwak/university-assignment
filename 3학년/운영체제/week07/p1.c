#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	pid_t pid;
	int n, add, mul;
	int i = 1;

	printf("양의 정수 입력: ");
	scanf("%d", &n);

	pid = fork();

	if(pid > 0)
	{
		add = 0;
		for(; i<=n; i++)
			add += i;
		printf("-- 1부터 %d까지의 합 = %d\n", n, add);
		sleep(1);
	}
	else if(pid == 0)
	{
		mul = 1;
		for(; i<=n; i++)
			mul *= i;
		printf("-- 1부터 %d까지의 곱 = %d\n", n, mul);
	}
	else
	{
		printf("fail to fork\n");
	}
	
	return 0;
}
