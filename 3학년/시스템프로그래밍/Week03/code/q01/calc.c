#include <stdio.h>

extern void add(int x, int y);
extern void sub(int x, int y);
extern void mul(int x, int y);

int main() {
	int menu;
	int x, y;

	printf("<Calculator Menu>\n");
	printf("1. Add\n");
	printf("2. Sub\n");
	printf("3. Mul\n");
	printf("Enter: ");
	scanf("%d", &menu);

	printf("Enter two numbers: ");
	scanf("%d %d", &x, &y);
	switch(menu) {
		case 1:
			add(x, y);
			break;
		case 2:
			sub(x, y);
			break;
		case 3:
			mul(x, y);
			break;
	}
	return 0;
}
