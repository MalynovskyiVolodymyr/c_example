#include <stdio.h>
#include <time.h>

void break_func(){
	printf("start break\n");
	for(;;){
		if(getchar())break;
	}
	printf("end break\n");
}

int main(){
	clock_t t = clock();
	break_func();
	t = clock() - t;
	double seconds = ((double) t)/CLOCKS_PER_SEC;
	printf("The processing time of function is: %f\n", seconds);
		
	return 0;
}
