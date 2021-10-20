# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/msg.h>
# include <fcntl.h>
# include <mqueue.h>
# define name "/q2uque"
# define MSG_STOP "/0"
# define MAX_SIZE 1000


//struct mq_attr {
//	long mq_flags;
//	long mq_maxmsg;
//	long mq_msgsize;
//	long mq_curmsgs;
//} attr;

int main (int argc, char **argv){
	mqd_t mq1;
	char buffer[MAX_SIZE];
	mq1 = mq_open(name,O_RDONLY|O_CREAT,0644,NULL);
	if(mq1==-1){
		perror("mq error:\n");
		exit(1);
	}
	printf("send to receiver:\n");
	do{
		for(int i=0; i<sizeof(buffer); i++){
			buffer[i]='\0';		
		}
		printf(">");
		fgets(buffer,MAX_SIZE,stdin);
		int send = mq_send(mq1,buffer,strlen(buffer)+1,0);
		if(send<0){
			perror("message:\n");
			exit(1);		
		}
	}while(1);
	return 0;
}
