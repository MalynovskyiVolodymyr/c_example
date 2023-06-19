include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
	//fork() -- creates copy of the current process
	if(fork() == 0){
		exit(0);
	}
	//wait stops cuurent process until new process ends
	pid_t cpid = wait(NULL);//it returns child process id
	
	printf("parrent process %d\n", getpid());
	printf("child process %d\n", cpid);
	return 0;
}
