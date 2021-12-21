#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;

void print_hello(const char *message);
void print_world(const char *message);

void print_hello(const char *message) {
	sleep(1);
	pthread_mutex_lock(&mutex1);

	printf("[%s] Hello\n", message);
	
	if(strcmp(message, "Thing 1") == 0)
		print_world(message);

	pthread_mutex_unlock(&mutex1);
}

void print_world(const char *message) {
	sleep(1);
	pthread_mutex_lock(&mutex2);
	
	printf("[%s] World\n", message);

	if(strcmp(message, "Thing 2") == 0)
		print_hello(message);

	pthread_mutex_unlock(&mutex2);
}

void *start_thread(void *message) {
	const char *msg = (const char *)message;

	if(strcmp(msg, "Thing 1") == 0)
		print_hello(msg);
	else
                print_world(msg);

	return message;
}

int main() {
	pthread_t thing1, thing2;

	const char *message1 = "Thing 1";
	const char *message2 = "Thing 2";

	pthread_create(&thing1, NULL, start_thread, (void *)message1);
	pthread_create(&thing2, NULL, start_thread, (void *)message2);

	pthread_join(thing1, NULL);
	pthread_join(thing2, NULL);

	return 0;
}
