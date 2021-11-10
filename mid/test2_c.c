#include <stdio.h>
#include <stdlib.h>
#include <string.h>	// for bzero()
#include <unistd.h>	// for close()
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>	// for inet_addr()
#include <string.h>
#define Server_PortNumber 5555
#define Server_Address "10.0.2.15"

int main(int argc, char *argv[]) {
	struct sockaddr_in address;
	int sock;
	int address_len = sizeof(address);
	int msg_size, res_size;
	char msg[50], res[50];
	sock = socket(PF_INET, SOCK_DGRAM, 0);
	if(!sock) {
		printf("Error: cannot create socket\n");
		exit(EXIT_FAILURE);
	}
	bzero(&address, address_len);
	address.sin_family = AF_INET;
	address.sin_port = htons(Server_PortNumber);
	address.sin_addr.s_addr = inet_addr(Server_Address); 

	int i=0,end = 0;
	while (!end) {
		printf("msg is %d\n",i);
		msg[0] = i + '0';
		msg[1] = '\0';
		msg_size = sendto(sock, msg, 50, 0, (struct sockaddr*)&address, address_len);
		if(msg_size < 0) {
			printf("Error: send fail");
			exit(EXIT_FAILURE);
		}
		else {
			res_size = recvfrom(sock, res, sizeof(res), 0, (struct sockaddr*)&address, &address_len);
			printf("server: %s\n", res);
			if (strcmp(res,"correct!") == 0){
				end = 1;
			}
			i+=1;
		}
	}

	return 0;
}
