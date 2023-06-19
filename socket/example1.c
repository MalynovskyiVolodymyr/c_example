#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

#define PORT 8080

int main(){
	int serv_fd, n_socket, v_read;
	struct sockaddr_in address;
	
	int opt = 1;
	int addr_length = sizeof(address);
	char buffer[1024] = {0};

	char *hello = "Hi! I'm a server!\n";

	if((serv_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		printf("Socket failed\n");
		exit(1);
	}

	if(setsockopt(serv_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
		printf("Socket failed\n");
		exit(1);
	}

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);

	if(bind(serv_fd, (struct sockaddr*)&address, sizeof(address)) < 0){
		printf("Socket server failure!\n");
	}


	if(listen(serv_fd, 3) < 0){
		printf("Socket error!\n");
		exit(1);
	}

	
	if((n_socket = accept(serv_fd, (struct sockaddr*)&address, (socklen_t*)&addr_length)) < 0 ){
		printf("Socket error!\n");
		exit(1);
	}

	v_read = read(n_socket, buffer, 1024);
	printf("buffer = %s\n",buffer);
	send(n_socket, hello, strlen(hello), 0);
	printf("Hello sent\n");


}
