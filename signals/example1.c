#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void signal_handler(int i){
	printf("signal SIGINT = %d\n", i);
	exit(0);
}

int main(){
	signal(SIGINT, signal_handler);
	while(1){
		printf("infinitive loop\n");
		sleep(3);
	}
}
