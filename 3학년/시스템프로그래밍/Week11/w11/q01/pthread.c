#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define BUFSIZE 100

struct StudentInfo {
	char name[BUFSIZE];
	char major[BUFSIZE];
	char univ[BUFSIZE];
};

void *start_thread(void *stu) {
	struct StudentInfo *stu_temp = (struct StudentInfo *)stu;
	int i;
	for(i=0; i<10; i++) {
		//sleep(1);
		printf("name: %s, major: %s, univ: %s\n", stu_temp->name, stu_temp->major, stu_temp->univ);
		//sleep(1);
	}
	return stu;
}

int main() {
	pthread_t thing1, thing2;
	struct StudentInfo stu1 = {"Brad Pitt", "Computer Engineering", "Holly University"};
	struct StudentInfo stu2 = {"Angelina Jollie", "Computer Science", "Wood University"};

	pthread_create(&thing1, NULL, start_thread, (void *)&stu1);
	pthread_create(&thing2, NULL, start_thread, (void *)&stu2);

	pthread_join(thing1, NULL);
	pthread_join(thing2, NULL);

	return 0;
}
