#include <stdio.h>
#include <stdlib.h>
#include <sys/times.h>
#include <limits.h>
#include <time.h>

#define SIZE 80000

void func_O1(int* arr);
void func_ON(int* arr);
void func_ON2(int* arr);

int main() {
	time_t t;
	struct tms mytms;
	clock_t t1, t2;
	int arr[SIZE];
	int i;
	double real_time;

	for(i = 0; i < SIZE; i++)
		arr[i] = 1;

	for(i = 0; i < 3; i++) {
		if((t1 = times(&mytms)) == -1) {
			perror("times 1");
			exit(1);
		}

		if(i == 0)
			func_O1(arr);
		else if(i == 1)
			func_ON(arr);
		else
			func_ON2(arr);

		if((t2 = times(&mytms)) == -1) {
			perror("times 2");
			exit(1);
		}
		
		real_time = (double)(t2 - t1) / (CLOCKS_PER_SEC / 10000);
		
		if(i == 0)
			printf("func_O1 takes %.4f seconds.\n", real_time);
		else if(i == 1)
			printf("func_ON takes %.4f seconds.\n", real_time);
		else
			printf("func_ON2 takes %.4f seconds.\n", real_time);
	}

	return 0;
}

void func_O1(int* arr) {
	int len = sizeof(arr);
}

void func_ON(int* arr) {
	long int sum = 0;
	int i;

	for(i = 0; i < SIZE; i++)
		sum += arr[i];
}

void func_ON2(int* arr) {
	long int sum = 0;
	int i, j;

	for(i = 0; i < SIZE; i++) {
		for(j = 0; j < SIZE; j++)
			sum += arr[i];
	}
}
