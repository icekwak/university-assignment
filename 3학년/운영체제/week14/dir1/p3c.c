#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#define SIZE sizeof(struct sockaddr_in)

main()
{
	int sockfd, filedes;
	char name[100] = "p3t.txt";
	char buf[6];

	struct sockaddr_in client = {AF_INET, INADDR_ANY, INADDR_ANY};

	int server_len = SIZE;
	struct sockaddr_in server = {AF_INET, 2007, INADDR_ANY};

	if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
	{
		printf("fail to call socket()\n");
		exit(1);
	}

	while(1)
	{
		if(sendto(sockfd, name, 100, 0, (struct sockaddr *)&server, server_len) == -1)
		{
			printf("fail to send name\n");
			exit(1);
		}
		printf("file name send\n");
		sleep(20);

		printf("file msg send\n");
		filedes = open(name, O_RDONLY);
		read(filedes, buf, 6);

		if(sendto(sockfd, buf, 6, 0, (struct sockaddr *)&server, server_len) == -1)
		{
			printf("fail to send message\n");
			exit(1);
		}

		close(filedes);
		exit(1);
	}
}
