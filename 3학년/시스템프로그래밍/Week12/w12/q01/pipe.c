#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 256

int main() {
	FILE* fp;
	char buf[BUFSIZE];

	fp = popen("ls / | grep s", "r");
	if(fp == NULL) {
		perror("pipe");
		exit(1);
	}

	while(1){
		if(fgets(buf, sizeof(buf), fp) == NULL)
			break;
        	printf("%s", buf);
	}
	pclose(fp);

	return 0;
}
