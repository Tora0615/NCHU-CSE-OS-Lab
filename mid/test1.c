#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main() {

	switch(fork()) {
		case -1:
			printf("fork error\n");
			exit(EXIT_FAILURE);
		case 0:	
			printf("I'm process D\n");
			printf("Pid: %d\tParent pid: %d\n", getpid(), getppid());
			exit(EXIT_SUCCESS);

		default:wait(NULL);
	}
	switch(fork()) {
		case -1:
			printf("fork error\n");
			exit(EXIT_FAILURE);
		case 0:	
			switch(fork()) {
				case -1:
					printf("fork error\n");
					exit(EXIT_FAILURE);
				case 0:	
					printf("I'm process G\n");
					printf("Pid: %d\tParent pid: %d\n", getpid(), getppid());
					exit(EXIT_SUCCESS);

				default:wait(NULL);
			}
			printf("I'm process C\n");
			printf("Pid: %d\tParent pid: %d\n", getpid(), getppid());
			exit(EXIT_SUCCESS);
		default:wait(NULL);
	}
	switch(fork()) {
		case -1:
			printf("fork error\n");
			exit(EXIT_FAILURE);
		case 0:	
			switch(fork()) {
				case -1:
					printf("fork error\n");
					exit(EXIT_FAILURE);
				case 0:	
					printf("I'm process F\n");
					printf("Pid: %d\tParent pid: %d\n", getpid(), getppid());
					exit(EXIT_SUCCESS);

				default:wait(NULL);
			}
			switch(fork()) {
				case -1:
					printf("fork error\n");
					exit(EXIT_FAILURE);
				case 0:	
					switch(fork()) {
						case -1:
							printf("fork error\n");
							exit(EXIT_FAILURE);
						case 0:	
							printf("I'm process H\n");
							printf("Pid: %d\tParent pid: %d\n", getpid(), getppid());
							exit(EXIT_SUCCESS);

						default:wait(NULL);
					}
					printf("I'm process E\n");
					printf("Pid: %d\tParent pid: %d\n", getpid(), getppid());
					exit(EXIT_SUCCESS);

				default:wait(NULL);
			}
			printf("I'm process B\n");
			printf("Pid: %d\tParent pid: %d\n", getpid(), getppid());
			exit(EXIT_SUCCESS);

		default:wait(NULL);
	}

	printf("I'm process A\n");
	printf("Pid: %d\tParent pid: %d\n", getpid(), getppid());
	return 0;
}
