#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){
	char* args[] = {
		"./example2",
		NULL
	};
	
	//execvp -- replesing cuurent process with the new process
	execvp(args[0], args);
	
	//this line will not going to be executed	
	printf("return to the caller example3.c\n");
}


