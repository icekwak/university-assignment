#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#define SIZE sizeof(struct sockaddr_in)
#define MSGSIZE 100

main()
{
	int sockfd;
	char recv_c[MSGSIZE];
	char send_c[MSGSIZE];
	struct sockaddr_in server = {AF_INET, 5000};

	server.sin_addr.s_addr = inet_addr("127.0.0.1");

	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		printf("fail to call socket()\n");
		exit(1);
	}

	if(connect(sockfd, (struct sockaddr *)&server, SIZE) == -1)
	{
		printf("fail to call connect()\n");
		exit(1);
	}

	while(1)
	{
		printf("Input a message\n");
		gets(send_c);

		send(sockfd, send_c, MSGSIZE, 0);

		if(recv(sockfd, recv_c, MSGSIZE, 0) > 0)
			printf("%s\n", recv_c);
		else
		{
			printf("server has no reply\n");
			close(sockfd);
			exit(1);
		}
	}
}
