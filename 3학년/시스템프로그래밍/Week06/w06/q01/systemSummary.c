#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <sys/utsname.h>
#include <string.h>

void printHelp();
void printUname(char* os, char* nodename, char* release, char* machine);

int main(int argc, char* argv[]) {
	
	if(argc == 1) {
		printHelp();
		exit(0);
	}
	
	struct utsname uts;
	int opt;
	char* os = "";
	char* nodename = "";
	char* release = "";
	char* machine = "";

	if(uname(&uts) == -1) {
		perror("uname");
		exit(1);
	}

	while((opt = getopt(argc, argv, "snvm")) != -1) {
		switch(opt) {
			case 's':
				os =  uts.sysname;
				strcat(os, " ");
				break;
			case 'n':
				nodename = uts.nodename;
				break;
			case 'v':
				release = uts.release;
				strcat(release, " ");
				break;
			case 'm':
				machine = uts.machine;
				strcat(machine, " ");
				break;
		}
	}
	printUname(os, nodename, release, machine);
	
	return 0;
}

void printHelp() {
		printf("systemSummary available options:\n");
		printf("-s : print OS name\n");
		printf("-n : print nodename(hostname)\n");
		printf("-v : print release\n");
		printf("-m : print machine info\n");
}

void printUname(char* os, char* nodename, char* release, char* machine) {
	if(strcmp(nodename, "") == 0)
		printf("This is a %s%s%smachine.\n", machine, release, os);
	else
		printf("This is a %s%s%smachine named %s.\n", machine, release, os, nodename);
}

