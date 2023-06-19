#include<stdio.h>
#include<unistd.h>

int main(){
	int proc_id, par_proc_id;
	proc_id = getpid();//get process id
	par_proc_id= getppid();//get parent process id

	printf("Process ID: %d\nParrent process ID: %d\n", proc_id, par_proc_id);
}
