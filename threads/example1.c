#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//gcc example1.c -o example1 -lpthread
void* myturn(void* args){
	int *iptr = (int *) args;
	int *sum = malloc(sizeof(int));	

	while((*iptr) != 0){
		sleep(1);
		printf("My Turn!\n");
		printf("passed args = %d\n", *iptr);
		(*iptr)--;
		(*sum) += (*iptr);
	}
	return sum;
}

void yourturn(){
	int count = 3;
	while(count != 0){
		sleep(2);
		printf("Your Turn!\n");
		count--;
	}
}

int main(){
	pthread_t newthread;
	int v = 5;
	int *result; 
	pthread_create(&newthread, NULL, myturn, &v);
	
	yourturn();

	//pthread_join will wait until thread is finishing 
	//second argument for reciving result
	pthread_join(newthread, (void*)&result);
	printf("result = %d\n", *result);
}
