#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>

#define PORT 8080

int main(){
	int sock,n_socket, v_read;
	struct sockaddr_in address;	
	char buffer[1024] = {0};

	char *hello = "Hello from client!\n";

	if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		printf("Socket failed\n");
		exit(1);
	}

	address.sin_family = AF_INET;
	address.sin_port = htons(PORT);
	
	if(inet_pton(AF_INET, "127.0.0.1", &address.sin_addr) <= 0){
		printf("error\n");
		exit(1);
	}

	if(connect(sock, (struct sockaddr*)&address, sizeof(address)) < 0){
		printf("error\n");
		exit(1);
	}	

	send(n_socket, hello, strlen(hello), 0);
	printf("Hello sent\n");
	v_read = read(n_socket, buffer, 1024);
	printf("buffer = %s\n",buffer);


}
