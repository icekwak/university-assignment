#include <stdio.h>
#include <stdlib.h>

FILE* fp;

void fileClose();

int main()
{
	char str[100];

	fp = fopen("a.txt", "r");
	if(fp == NULL)
	{
		printf("fail to fopen\n");
		return -1;
	}

	fgets(str, 100, fp);
	printf("%s\n", str);

	atexit(fileClose);
	exit(0);
	return 0;
}

void fileClose()
{
	printf("close file\n");
	fclose(fp);
}
