#include<stdio.h>
#include<stdlib.h>

struct threeNumb{
	int num1, num2, num3;
};
typedef struct threeNumb threeNumb;

int main(){
	int num;
	threeNumb number;
	FILE *fptr;

	if((fptr=fopen("file1.bin","wb")) == NULL){
		printf("cannot open a file\n");
		exit(1);
	}
	
	for(num=1; num < 5; ++num){
		number.num1=num;
		number.num2=2*num;
		number.num3=2*num+3;
		fwrite(&number, sizeof(threeNumb), 1, fptr);
	}
	fclose(fptr);
}
