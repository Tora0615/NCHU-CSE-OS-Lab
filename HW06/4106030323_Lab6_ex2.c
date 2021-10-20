# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>

int main(){
	if(fork()==0){
		printf("I am child process E.\n");	
		printf("pid : %d, Parent pid : %d\n",getpid(), getppid());	
		return 0;
	}
	wait(NULL);
	if(fork()==0){
		printf("I am child process D.\n");		
		printf("pid : %d, Parent pid : %d\n",getpid(), getppid());	
		return 0;
	}
	wait(NULL);
	if(fork()==0){
		if(fork()==0){
			printf("I am child process C.\n");
			printf("pid : %d, Parent pid : %d\n",getpid(), getppid());
			return 0;	
		}
		wait(NULL);
		printf("I am child process B.\n");
		printf("pid : %d, Parent pid : %d\n",getpid(), getppid());
		return 0;
	}
	wait(NULL);
	printf("I am child process A.\n");
	printf("pid : %d, Parent pid : %d\n\n",getpid(), getppid());
	return 0;
}
