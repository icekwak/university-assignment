#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#define SIZE sizeof(struct sockaddr_in)

main()
{
	int sockfd;
	char msg, prev;

	struct sockaddr_in client = {AF_INET, INADDR_ANY, INADDR_ANY};

	int server_len = SIZE;
	struct sockaddr_in server = {AF_INET, 2007, INADDR_ANY};

	if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
	{
		printf("fail to call socket()\n");
		exit(1);
	}

	if(connect(sockfd, (struct sockaddr *)&server, SIZE) == -1)
	{
		printf("fail to call connevt()\n");
		exit(1);
	}

	prev = '\n';
	while(read(0, &msg, 1) != 0)
	{
		if(send(sockfd, &msg, 1, 0) == -1)
		{
			printf("fail to send message\n");
			continue;
		}

		if(recv(sockfd, &msg, 1, 0) == -1)
		{
			printf("fail to receive message\n");
			continue;
		}
		
		printf("%s%c", (prev == '\n')?"[recv] ":"", msg);
		prev = msg;
	}
}
