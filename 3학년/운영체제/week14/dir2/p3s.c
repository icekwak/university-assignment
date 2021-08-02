#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define SIZE sizeof(struct sockaddr_in)

main()
{
	int sockfd, filedes;
	char name[100];
	char buf[6];

	struct sockaddr_in server = {AF_INET, 2007, INADDR_ANY};

	struct sockaddr_in client;
	int client_len = SIZE;

	if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
	{
		printf("fail to call socket()\n");
		exit(1);
	}

	if(bind(sockfd, (struct sockaddr *)&server, SIZE) == -1)
	{
		printf("fail to call bind()\n");
		exit(1);
	}

	
	while(1)
	{
		sleep(10);
		printf("file name recv\n");
		if(recvfrom(sockfd, name, 100, 0, (struct sockaddr *)&client, &client_len) == -1)
		{
			printf("fail to recv name\n");
			exit(1);
		}

		sleep(30);
		printf("file msg recv\n");
		filedes = creat(name, 0644);
		filedes = open(name, O_WRONLY);

		if(recvfrom(sockfd, buf, 6, 0, (struct sockaddr *)&client, &client_len) == -1)
		{
			printf("fail to receive message\n");
			continue;
		}
		write(filedes, buf, 6);
		close(filedes);
		exit(1);
	}
}
