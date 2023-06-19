#include <stdio.h>
#include <stdlib.h>

int main(){
	for(int i = 0; i < 5; i++){
		char *ptr = malloc(5000000); // 5Mb
		printf("Got memory! (Address=%p)\n", ptr);
	}
}
