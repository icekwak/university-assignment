#include <ncurses.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define BUF_SIZE 20

int main(int argc, char* argv[]) {
	if(argc != 2 && argc != 3) {
		printf("[help] ./processDashboard -r <count>\n");
		exit(EXIT_FAILURE);
	}

	if(strcmp(argv[1], "-r") != 0) {
		printf("option : -r\n");
		exit(EXIT_FAILURE);
	}

	int cnt = 5;
	int i = 0;
	FILE* fp;
	char buf[BUF_SIZE] = {0,};

	if(argc == 3)
		cnt = atoi(argv[2]);

        initscr();

        mvprintw(0, 0, "<Process Dashboard>");
        mvprintw(2, 0, "* Running Process (%d) :", cnt);
	while(1) {
                system("./getPids.sh");
		fp = fopen("pids.txt", "r");
		
		i = 0;
		while(fgets(buf, BUF_SIZE, fp)) {
			mvprintw(3+i, 0, "%s", buf);
			memset(buf, '\0', BUF_SIZE);
			i++;
			
			if(i >= cnt)
				break;
		}
		
		for(i; i<=cnt; i++)
			mvprintw(3+i, 0, "     ");
		
		fclose(fp);
                refresh();
                sleep(1);
        }
        endwin();

	return 0;
}
