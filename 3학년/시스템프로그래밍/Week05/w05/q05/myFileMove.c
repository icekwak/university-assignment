#include <stdio.h>

int main(int argc, char* argv[]) {
	char* old_file = argv[1];
	char* new_file = argv[2];
	
	rename(old_file, new_file);
	
	return 0;
}
