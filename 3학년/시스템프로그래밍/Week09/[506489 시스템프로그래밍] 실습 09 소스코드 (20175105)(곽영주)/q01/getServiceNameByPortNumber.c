#include <stdio.h>
#include <netdb.h>

int main() {
	struct servent* port;
	int port_num;

	printf("Enter to Port Number: ");
	scanf("%d", &port_num);

	port = getservbyport(htons(port_num), "tcp");
	printf("Port(%d) Name: %s\n", port_num, port->s_name);

	return 0;
}
