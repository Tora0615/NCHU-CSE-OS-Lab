# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>

int main(int argc, char **argv){
	FILE* cptr;
	int temp;
	printf("my real id=%d\n",getuid());
	printf("my effective id=%d\n",geteuid());

	// New Part
	if(seteuid(0)!=0){
		printf("seteuid failed\n");
		return 0;
	}

	cptr=fopen("datafile","a");
	if(cptr==NULL){
		printf("can't open file!\n");
		return 0;
	}
	fprintf(cptr,"my real id=%d\n",getuid());
	fprintf(cptr,"my effective id=%d\n",geteuid());
	fclose(cptr);
	return 0;
}
