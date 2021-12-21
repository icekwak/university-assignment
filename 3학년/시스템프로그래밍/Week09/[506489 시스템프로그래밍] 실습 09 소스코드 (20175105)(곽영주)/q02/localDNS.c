#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
	
	if(argc != 2) {
		printf("./localDNS <hostname>\n");
		exit(1);
	}

	struct hostent* hent;
	struct in_addr in;
	char* hostname = argv[1];

	if((hent = gethostbyname(hostname)) == NULL) {
		printf("Not Found\n");
		exit(1);
	}

	memcpy(&in.s_addr, *hent->h_addr_list, sizeof(in.s_addr));
	printf("Name: %s, IP: %s\n", hent->h_name, inet_ntoa(in));

	return 0;
}
