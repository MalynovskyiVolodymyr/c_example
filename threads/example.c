#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <pthread.h>

void* new_function(void* args){
	/*
	char* myarray[] = {
		"./example2",
		NULL
	};
	execvp(myarray[0], myarray);
	*/
	sleep(2);
	return NULL;
}

//TO COMPILE THIS -lpthread lib need to be used
int main(){
	pthread_t thread_id;
	pthread_create(
		&thread_id, 
		NULL, 
		new_function,
		NULL
	);
	pthread_join(thread_id, NULL);
	printf("Hello from example4.c\n");
	return 0;
}
