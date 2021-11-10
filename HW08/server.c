#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define PortNumber 5555

int main(int argc,char *argv[]) {
	struct sockaddr_in address,client_address;
	int sock,byte_recv,client_address_length,byte_sent;
	char buffer[50];
	sock = socket(PF_INET,SOCK_DGRAM,0);
	if(sock<0) printf("Error");
	bzero(&address,sizeof(address));
	address.sin_family = AF_INET;
	address.sin_port = htons(PortNumber);
	address.sin_addr.s_addr=INADDR_ANY;
	if(bind(sock,(struct sockaddr*)&address,sizeof(address)) ==-1) {
		printf("error");
		return 0;
	}
	int address_length = sizeof(address);
	printf("ready\n");
	for(;;) {
		byte_recv = recvfrom(sock,buffer,sizeof(buffer),0,(struct sockaddr*)&address,&address_length);
		if(byte_recv<0) printf("Error recv packet\n");
		printf("receive data: %s\n",buffer);
		byte_sent=sendto(sock,"hihihi",6,0,(struct sockaddr*)&address,address_length);
		if(byte_sent<0) printf("replyerror\n");
	}
	return 0;
}
