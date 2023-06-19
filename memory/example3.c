#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main(){
	char* new_file = "/home/volodymyr_malynovskyi/Documents/Linux/C_repeat/memory/example";
	char* new_dir = "/home/volodymyr_malynovskyi/Documents/Linux/C_repeat/memory/NewDir";

	unlink(new_file);
	
	if(rmdir(new_dir) != 0){
		printf("cannot remove directory\n");
	}
}
