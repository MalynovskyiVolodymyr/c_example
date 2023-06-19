#include<stdio.h>
#include<stdlib.h>

int main(){
	int num;
	FILE *fptr;
	
	if((fptr = fopen("file1.txt", "r")) == NULL){
		printf("error cannot open a file\n");
		exit(1);
	}

	fscanf(fptr, "%d", &num);
	printf("value of num=%d\n", num);
	fclose(fptr);
}
