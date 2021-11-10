#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define RANGE 250000

void *PrintHello(void *arg){
	int i;
	for (i=0; i<RANGE; i++){
		*(int*)arg = *(int*)arg + 1;
		//printf("Thread ID : %lu, ",pthread_self());
		//printf("num is : %d\n",*(int*)arg);
	}
	printf("num is : %d\n",*(int*)arg);
	int re = 1;
	pthread_exit((void*)re);
}

int main(){
	pthread_t thread[4];
	int rc, count=0, i;
	for (i=0;i<4;i++){
		rc = pthread_create(&thread[i], NULL, PrintHello, &count);
		printf("thread %d created\n",i);
		if(rc){
			printf("CREATE ERROR");
			exit(-1);
		}
	}
	for (i=0;i<4;i++){
		void *ret;
		rc = pthread_join(thread[i], &ret);
		printf("thread %d complete\n",i);
		if(rc){
			printf("JOIN ERROR");
			exit(-1);
		}
	}
	printf("Complete! count value :%d\n",count);
}


// compile : 
// gcc -o 01 01_pthreads.c -pthread
