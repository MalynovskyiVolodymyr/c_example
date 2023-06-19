#include <stdlib.h>
#include <stdio.h>


void sort3(int* a){
	int t;
	
	if(a[1] > a[2]){
		t = a[1];	
		a[1] = a[2];
		a[2] = t;
	}
	if(a[1] > a[3]){
		t = a[1];
		a[1] = a[3];
		a[3] = t;
	}
	if(a[2] > a[3]){
		t = a[2];
		a[2] = a[3];
		a[3] = t;
	}
}

void sort3_test(){
	int a[4] = {0,24,33,14};
	sort3(a);
	for(int i = 1; i < 4; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}
///
void selection(int a[], int N){	
	int i,j,min,t;

	for(i = 1; i < N; i++){
		min = i;
	
		for(j = i+1; j <= N; j++){
			if(a[j] < a[min]){
				min = j;
			}
		}		

		t = a[min];
		a[min] = a[i];
		a[i] = t;
	}
}

void testSelection(){
	int a[100];
	a[0]=0;
	for(int i = 99; i > 0; i--){
		a[i] = i;
	} 

	selection(a, 99);
	for(int i = 0; i < 100; i++){
		printf("%4d",a[i]);
	}
	printf("\n");
}
//
void insertion(int a[], int N){
	int index, j, value;
	for(index = 2; index <= N; index++){
		value = a[index];
		j = index;
		
		while(a[j-1] > value){
			a[j] = a[j-1]; 
			j--;
		}
		a[j] = value;
	}
}
void testInsertion(){
	int a[100];
	a[0]=0;
	for(int i = 99; i > 0; i--){
		a[i] = i;
	} 

	insertion(a, 99);
	for(int i = 0; i < 100; i++){
		printf("%4d",a[i]);
	}
	printf("\n");
}
//
void bubble(int a[], int N){
	int index, j, t;

	for(index = N; index >= 1; index--){
		for(j = 2; j <= index; j++){
			if(a[j-1] > a[j]){
				t = a[j-1];
				a[j-1] = a[j];
				a[j] = t;
			}
		}
	}
}
//
void main(void){
	//sort3_test();
	//testSelection();
	testInsertion();
}


