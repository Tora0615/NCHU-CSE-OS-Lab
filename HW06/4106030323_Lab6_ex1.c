# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>

int gol = 10;

int main(int argc, char **argv){
	int loc = 10;
	printf("init global : %d, init local : %d\n",gol,loc);	
	
	if(fork()==0){
		loc += 10;
		gol += 10;
		printf("\nChild\n");
		printf("pid : %d, Parent pid : %d\n",getpid(), getppid());
		printf("global : %d, local : %d\n",gol,loc);	
		return 0;
	}
	wait(NULL);
	printf("\nParent\n");
	printf("pid : %d, Parent pid : %d\n",getpid(), getppid());
	printf("global : %d, local : %d\n",gol,loc);		
	return 0;
}
