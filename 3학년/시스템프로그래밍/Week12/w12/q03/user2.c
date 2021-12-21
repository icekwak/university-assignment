#include <sys/msg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define BUFSIZE 80

struct Smymsgbuf {
	long mtype;
	char mtext[BUFSIZE];
};

struct Rmymsgbuf {
	long mtype;
        char mtext[BUFSIZE];
};

// 메시지 전송
void *start_send(void *s_mesg) {
	struct Smymsgbuf *mesg = (struct Smymsgbuf *)s_mesg;
	char buf[BUFSIZE];
	key_t key;
	int msgid;

	key = ftok("user2", 1);
        msgid = msgget(key, IPC_CREAT|0644);
        if(msgid == -1) {
                perror("msgget");
                exit(1);
        }

	while(1) {
		memset(buf, '\0', BUFSIZE);
		gets(buf);
		
		mesg->mtype = 2;
		strcpy(mesg->mtext, buf);

		if(msgsnd(msgid, (void *)&mesg, BUFSIZE, IPC_NOWAIT) == -1) {
			perror("msgsnd");
			exit(1);
		}

		if(strcmp(buf, "<EXIT>") == 0) {
			printf("====== [EXIT] ======\n");
			exit(0);
		}
	}
	
	return s_mesg;
}

// 메시지 수신
void *start_recv(void *r_mesg) {
        struct Rmymsgbuf *inmsg = (struct Rmymsgbuf *)r_mesg;
	key_t key;
	int msgid, len;

	key = ftok("user1", 1);
	if((msgid = msgget(key, 0)) < 0) {
		perror("msgget");
		exit(1);
	}
	
	while(1) {
		len = msgrcv(msgid, inmsg, BUFSIZE, 0, 0);
		printf(">>> %s\n", inmsg->mtext);

		if(strcmp(inmsg->mtext, "<EXIT>") == 0) {
			printf("====== [EXIT] ======\n");
                        exit(0);
		}
	}

        return r_mesg;
}

int main() {
	pthread_t sender, receiver;
	struct Smymsgbuf s_mesg;
	struct Rmymsgbuf r_mesg;

	pthread_create(&sender, NULL, start_send, (void *)&s_mesg);
	pthread_create(&receiver, NULL, start_recv, (void *)&r_mesg);

	pthread_join(sender, NULL);
	pthread_join(receiver, NULL);

	return 0;
}
