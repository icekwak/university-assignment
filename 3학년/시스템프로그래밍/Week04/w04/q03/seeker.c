#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUF_SIZE 100

int main(int argc, char *argv[]) {
	if(argc != 4) {
		printf("./seeker <filename> <start position> <bytes to read>\n");
		exit(1);
	}

	char *filename = argv[1];
	char *start_char = argv[2];
	int start_int = 0;
	int read_bytes = atoi(argv[3]);

	FILE *fp;
	int file_total_bytes = 0;
	char n_buf[BUF_SIZE] = {0,};
	char m_buf[BUF_SIZE] = {0,};
	int n, m;
	
	fp = fopen(filename, "r");
	if(fp == NULL) {
		perror("failed to open file");
		exit(1);
	}

	/* check if a start position is a 'number' or 'character' */
	if(isalpha(start_char[0]) > 0) {
		if(strcmp(start_char, "begin") == 0) // start position is a 'begin'
			rewind(fp);
		else if(strcmp(start_char, "end") == 0)	// start position is a 'end'
			fseek(fp, 0, SEEK_END);
		else if(strcmp(start_char, "mid") == 0) { // start position is a 'mid'
			fseek(fp, 0, SEEK_END);
			file_total_bytes = ftell(fp) - 1;
			rewind(fp);

			if(file_total_bytes % 2 == 0) // even
				fseek(fp, file_total_bytes/2, SEEK_CUR);
			else // odd
				fseek(fp, (file_total_bytes/2)+1, SEEK_CUR);
		}
		else {
			printf("<start position> is a 'character'\n");
			exit(1);
		}
	}
	else {
		start_int = atoi(start_char);

		if(start_int >= 0) // start position is a 'forward'
			fseek(fp, start_int, SEEK_CUR);
		else // start position is a 'reverse'
			fseek(fp, start_int-1, SEEK_END);
	}

	n = fread(n_buf, sizeof(char), read_bytes, fp);
	
	while(n < read_bytes) {	
		n_buf[n-1] = '\0';
		rewind(fp);
		
		if(n == 0)
			m = fread(m_buf, sizeof(char), read_bytes-n, fp);
		else
			m = fread(m_buf, sizeof(char), read_bytes-n+1, fp);
	
		m_buf[m] = '\0';		
		strncat(n_buf, m_buf, strlen(m_buf));
		n += m;
	}
	n_buf[n] = '\0';

	printf("%s\n", n_buf);
	fclose(fp);
	return 0;
}
