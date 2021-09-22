# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>

int main(int argc, char **argv){
	printf("Real UID=%d\nEffective UID=%d\n",getuid(),geteuid());
	return 0;
}
