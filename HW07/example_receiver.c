# include <fcntl.h>
# include <mqueue.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdlib.h>

# define name "/q2uque"
# define MAX_SIZE 1000



int main (int argc, char **argv){
	mqd_t mq1;
	char buffer[MAX_SIZE+1];
	struct mq_attr attr;
	int must_stop=0; 
	int tmp=0;
	mq1 = mq_open(name,O_RDONLY|O_CREAT,0644,NULL);
	if(mq1==-1){
		perror("mq error:\n");
		exit(1);
	}
	do{
		ssize_t bytes_read;
		bytes_read = mq_receive(mq1,buffer,8192,NULL);
		if(bytes_read<0){
			perror("bytes_read error\n");
			exit(1);
		}		
		buffer[bytes_read]='\0';
		printf("received:%s",buffer);
	}while(1);
	int s_close = mq_close(mq1);
	if(s_close==-1){
		perror("s_close error:\n");
		exit(1);
	}	
	tmp = mq_unlink(name);
	if(-1==tmp){
		printf("error");
		exit(0);
	}
	return 0;
}
