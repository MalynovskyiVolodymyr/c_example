#include <stdio.h>

int main(){
	char buff[BUFSIZ];
	FILE *fp = popen("ls", "r");
	
	while(fgets(buff, BUFSIZ, fp) != NULL){
		printf("LS: %s", buff);
	}
	pclose(fp);
	printf("BUFSIZ %ld\n", BUFSIZ); 
}
