#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
	char* name = argv[1];

	if((argc != 3) || (strcmp(name, "PATH") != 0)) {
		printf("findEnv help : ./findEnv PATH <str>\n");
		exit(1);
	}

	char* path = getenv(name);
	char* keyword = argv[2];
	int size = strlen(path) - strlen(keyword);
	int i = 0;

	for(i; i < size; i++) {
		if(strncmp(keyword, path + i, strlen(keyword)) == 0) {
			printf("%s has %s!\n", name, keyword);
			exit(0);
		}
	}
	printf("%s does not have %s\n", name, keyword);

	return 0;
}
