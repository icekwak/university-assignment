#include <stdio.h>
#include <stdlib.h>

void print(int n, int size, int sum);

int main() {
	int size = 10;	// array size (default)
	int n = 0;	// data count in array
	int *arr;	// array
	int sum = 0;	// data sum in array
	int i;

	arr = calloc(size, sizeof(int));
	print(n, size, sum);

	// array size up
	for(i=0; i<100; i++) {
		arr[i] = i + 1;
		++n;

		if(n == size) {
			size *= 2;
			arr = realloc(arr, sizeof(int) * size);
		#ifdef DEBUG
			printf("Size up: %d => %d\n", size/2, size);
		#endif
		}
	}

	for(i=0; i<n; i++)
		sum += arr[i];

	print(n, size, sum);

	// array size down
	for(i=100; i>10; i--) {
		arr[i-1] = 0;
		--n;

		if(n == size/4) {
			size /= 4;
			arr = realloc(arr, sizeof(int) * size);
		#ifdef DEBUG
			printf("Size down: %d => %d\n", size*4, size);
		#endif
		}
	}

	sum = 0;
	for(i=0; i<n; i++)
		sum += arr[i];

	print(n, size, sum);

	free(arr);
	return 0;
}

void print(int n, int size, int sum) {
	printf("n (data count in array):     %d\n", n);
	printf("size (array size (default)): %d\n", size);
	printf("sum (data sum in array):     %d\n", sum);
	printf("-------------------------------\n\n");
}
