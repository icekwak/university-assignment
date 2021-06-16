#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

main()
{
	pid_t pid;
	int filedes;
	char sumValueText[] = "p1_sumValue.txt";
	int status, i;
	int x, y;
	char sumValue[10];
	int sumInt;
	ssize_t n;
	
	while(1)
	{
		printf("=== x, y값은 10이하이며, x < y 조건 성립 ===\n");
		
		printf("x = ");
		scanf("%d", &x);
		printf("y = ");
		scanf("%d", &y);

		if(x <= 10 && y <= 10 && x < y)
			break;
	}

	pid = fork();
	if(pid > 0 )
	{
		int pow = 1;
		for(i = 0; i < y; i++ )
			pow *= x;
		printf("%d의 %d승 = %d\n", x, y, pow);
		
		wait(&status);
		filedes = open(sumValueText, O_RDONLY);
		if(filedes == -1)
			printf("parent: file open error\n");
		else
		{
			n = read(filedes, sumValue, 10);
			if(n < 1)
				printf("parent: file read error\n");
			else
			{
				sumInt = atoi(sumValue);
				printf("%d + %d = %d\n", pow, sumInt, pow + sumInt);
			}
			close(filedes);
		}
		exit(0);
	}
	else if(pid == 0)
	{
		int sum = 0;
		for(i = x; i <= y; i++)
			sum += i;
		printf("%d부터 %d까지의 합 = %d\n", x, y, sum);

		filedes = open(sumValueText, O_WRONLY);
		if(filedes == -1)
			printf("child: file open error\n");
		else
		{
			sprintf(sumValue, "%d", sum);
			n = write(filedes, sumValue, 10);
			if(n != 10)
				printf("child: file write error\n");
			close(filedes);
		}
		exit(0);
	}
	else
		printf("fail to fork\n");
}
