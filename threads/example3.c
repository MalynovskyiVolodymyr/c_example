#include <stdio.h>
#include <signal.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

// it tells the compiller that this variable is going to be changed
// it has afect only with multithreaded application there
// compliller dosent know how to optimize the code
volatile bool done = false;

void* tfunc(void* arg){
	sleep(1);
	done = true;
	return NULL;
}

int main(){
	pthread_t t1;
	pthread_create(&t1, NULL, tfunc, NULL);

	printf("Waiting...\n");

	// in here compiler can replase --!done with the true{infinitive loop}
	while(!done){}
	printf("Ok. Moving on.\n");
}
