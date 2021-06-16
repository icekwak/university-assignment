#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd;
	ssize_t nread;
	int i = 0;	
	int num = 0;	
	char str[20] = "";	
	
	fd = open("task.txt", O_RDONLY);
	nread =  read(fd, str, sizeof(str));
	
	if(nread > 0)
	{
		for(i; i < 20 ; i++)
		{
			if(('a' <= str[i] && 'z' >= str[i])
				|| ('A' <= str[i] && 'Z' >= str[i]))
			{
				num++;
			}
		}		
		printf("num : %d\n", num);
	}
	else
	{
		printf("error\n");
	}
	
	close(fd);
	return 0;
}
