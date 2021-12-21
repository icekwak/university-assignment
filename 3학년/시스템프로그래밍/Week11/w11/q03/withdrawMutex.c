#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFSIZE 100

struct Account { // 공용통장
	int saving;
	int balance;
	pthread_mutex_t mutex;
};

struct User { // 공용통장 사용자
	char name[BUFSIZE];
	int amount;
	struct Account *account;
};

void disburse_money(struct Account *account, int amount, char *name) {
	printf("[%s] saving: %d, balance: %d, amount: %d\n", name, account->saving, account->balance, amount);

	account->saving = account->balance;
}

int withdraw(struct Account *account, int amount, char *name) {
	
	pthread_mutex_lock(& account->mutex);
	sleep(1);

	const int balance = account->balance;
	
	if(balance < amount){
		disburse_money(account, amount, name);
		
		pthread_mutex_unlock(& account->mutex);
		sleep(1);

		return -1;
	}

	sleep(1);
	account->balance = balance - amount;

	disburse_money(account, amount, name);

	pthread_mutex_unlock(& account->mutex);
	sleep(1);

	return 0;
}

void *start_thread(void *user) {
	struct User *user_temp = (struct User *)user;
	
	int result = withdraw(user_temp->account, user_temp->amount, user_temp->name);

	if(result == -1)
		printf("[%s] 잔액부족\n", user_temp->name);
	else
		printf("[%s] 인출성공\n", user_temp->name);

	return user;
}

int main() {
	pthread_t thing1, thing2;
	struct Account account = {500, 500};
	struct User user1 = {"user1", 400, &account};
	struct User user2 = {"user2", 300, &account};
	
	pthread_create(&thing1, NULL, start_thread, (void *)&user1);
	pthread_create(&thing2, NULL, start_thread, (void *)&user2);

	pthread_join(thing1, NULL);
	pthread_join(thing2, NULL);

	return 0;
}
