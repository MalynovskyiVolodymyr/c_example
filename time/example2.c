#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/utsname.h>

int main(){
	struct utsname buff;
	
	errno=0;
	
	if(uname(&buff) != 0){
		perror("uname say's buff is not null, so there is an error!\n");
		exit(EXIT_FAILURE);
	}

	printf("System Name = %s\n", buff.sysname);
	printf("Node Name = %s\n", buff.nodename);
	printf("Release = %s\n", buff.release);
	printf("Version = %s\n", buff.version);
	printf("Machine = %s\n", buff.machine);
}
