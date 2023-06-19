#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void simple_fork(){
	// if I'm child fork returns 0
	if(fork() == 0){
		printf("I'm childish.\n");
	}else{
		printf("I'm old and parental. %d\n", getpid());
	}
}
//
#include <sys/types.h>
#include <sys/wait.h>
// man 2 wait
// man 2 unistd // manuals
void example_fork(){
	pid_t pid = fork();
	if(pid < 0){
		perror("Fork failed\n");
	}
	if(pid == 0){
		printf("I am the child with pid %d\n", (int)pid);
		sleep(5);
		printf("Child exiting...\n");
		exit(0);
	}

	// We must be the parent
	printf("I'm the parent process, waiting for the child to exit pid=%d\n",
						getpid());
	wait(NULL); // if not wait parrent will stop before child ))
	printf("Parent process end\n"); 
	
}

int main (){
	example_fork();
	return 0;
}
