#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <mqueue.h>
#define name "/q2uque"
#define MSG_STOP "exit"
#define MAX_SIZE 1000
int main(int argc,char **argv) {
	mqd_t mq1;
	char buffer[MAX_SIZE];
	mq1=mq_open(name,O_WRONLY|O_CREAT,0644,NULL);
	if(mq1==-1) {
		perror("mq1 error:\n");
		exit(1);
	}
	printf("send to receiver : \n");
	do {
		for (int i=0;i<sizeof(buffer);i++) {
			buffer[i]='\0';
		}
		printf(">");
		fgets(buffer,MAX_SIZE,stdin);
		int send=mq_send(mq1,buffer,strlen(buffer)+1,0);
		if(!strncmp(buffer,"exit",4)) {
			return 0;
		}
		if(send<0) {
			perror("message:\n");
			exit(1);
		}
	}while(1);
	return 0;
}
