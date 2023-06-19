#include <stdlib.h>
#include <stdio.h>

int main(){
	int *ptr;
	int num=8, sum=0;

	//ptr = (int*)malloc(num*sizeof(int));
	ptr = (int*)calloc(num,sizeof(int));

	for(int i=0; i < num; i++){
		ptr[i]=i+1;
	}
	for(int i=0; i < num; i++){
		printf("element %d = %d\n", i, ptr[i]);
	}
	printf("-----------------------------------\n");

	int newSize = 16 * sizeof(int);
	ptr = realloc(ptr, newSize);
	
	for(int i=7; i < 16; i++){
		ptr[i]=i+1;
	}
	for(int i=0; i < 16; i++){
		printf("element %d = %d\n", i, ptr[i]);
	}
	
	free(ptr);
	return 0;
}
