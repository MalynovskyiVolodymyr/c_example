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

	if((fptr=fopen("file1.bin","rb")) == NULL){
		printf("Error cannot open the file\n");
	}

	for(num=1; num < 5;++num){
		fread(&number, sizeof(threeNumb),1,fptr);
		printf("%d %d %d\n",number.num1,number.num2,number.num3);
	}
	fclose(fptr);
}
