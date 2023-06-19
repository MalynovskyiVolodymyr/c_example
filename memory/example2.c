#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
	int res = mkdir("/home/volodymyr_malynovskyi/Documents/Linux/C_repeat/memory/NewDir2", 0777);
	if(res == 0){
		printf("directory was created\n");
	}else{
		printf("error cannot create a directory\n");
	}
	return 0;
}
