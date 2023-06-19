#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void doSomeWork(){
	const int NUM_TIMES = 5;
	for(int i = 0; i < NUM_TIMES; i++){
		sleep(rand() % 4); // random number from  0 - 3
		printf("Done pass %d\n", i);
	}
}

void example(){
	printf("before fork() the process leaves signle\n");

	pid_t pid = fork();
	
	printf("fork() duplicates current process\n");
	if(pid < 0){
		perror("Fork failed\n");
		exit(1);
	}
	if(pid == 0){
		printf("I'm the child process\n");
		doSomeWork();
		exit(0);
	}

	printf("I'm the parent process id = %d\n", getpid());
	wait(NULL);
	printf("Parent ending.\n");
	
}

int main(int argc, char *argv[]){
	example();
	return 0;
}
