#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// note if I will share global value
// to this function the value will
// not be unique so it will copy it
// into the memory in each process
void doSomeWork(char *processName){
	const int NUM_TIMES = 5;
	for(int i = 0; i < NUM_TIMES; i++){
		sleep(rand() % 4);
		printf("Done pass %d for %s\n", i, processName);
	}
}

void example(void){
	pid_t pid = fork();
	srand((int) pid); //spit process to async
	
	if(pid < 0){
		perror("Fork failed\n");
		exit(1);
	}
	
	if(pid == 0){
		printf("I'm the child process pid %d\n", getpid());
		doSomeWork("Child");
		exit(42); // return walue to waited parent
	}

	printf("I'm parent process, waiting for the child to finish.\n");
	doSomeWork("Parent");
	int responce;
	pid_t childPid = wait(&responce);

	printf("Parent ending.\nChild id=%d\nResponce value=%d\n", 
					(int)childPid, 
					WEXITSTATUS(responce));
	// WEXITSTATUS decrypt the responce
}

int main(int atgc, char* argc[]){
	example();
}
