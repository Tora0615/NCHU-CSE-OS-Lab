#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define Server_PortNumber 5555
#define Server_Address "10.0.2.15"

int main(int argc,char *argv[]) {
	struct sockaddr_in address;
	int sock, byte_sent,byte_recv;
	char buffer[50];
	char rebuffer[50];
	printf("Please enter a string:\n");
	scanf("%s",buffer);
	sock=socket(PF_INET,SOCK_DGRAM,0);
	if(sock<0) 
		printf("Error!\n");
	bzero(&address,sizeof(address));
	address.sin_family = AF_INET;
	address.sin_port = htons(Server_PortNumber);
	address.sin_addr.s_addr=inet_addr(Server_Address);
	printf("after htons,port is translate to %d\n",address.sin_port);
	printf("ready, start to send data \n ---- \n");
	int address_length = sizeof(address);
	byte_sent = sendto(sock,buffer,sizeof(buffer),0,(struct sockaddr*)&address,address_length);
	if(byte_sent<0)
		printf("Error!");
	byte_recv=recvfrom(sock,rebuffer,sizeof(rebuffer),0,(struct sockaddr*)&address,&address_length);
	if(byte_recv<0) printf("recv reply error");
	printf("server :%s",rebuffer);
	close(sock);
	return 0;
}
