#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {
	char mesg[] = "Just a string";
	int row, col;
	int row_rand, col_rand;

	initscr();
	getmaxyx(stdscr, row, col);

	srand(time(NULL));
	row_rand = rand() % (row + 1);
	col_rand = rand() % (col + 1);

	mvprintw(row_rand, col_rand - strlen(mesg), "%s", mesg);

	mvprintw(row-2, 0, "This screen has %d rows and %d columns\n", row, col);
	printw("Try resizing your window(if possible) and then run this program again");
	refresh();
	getch();
	endwin();

	return 0;
}
