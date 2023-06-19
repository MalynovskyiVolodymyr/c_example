#include <stdio.h>
#include <time.h>

int gcd(int u, int v){
	int t;
	while(u >0){
		if(u < v){
			t = u;
			u = v;
			v = t;
		}
		u = u - v;
	}
	return v;
}
///
void getGreatestCommonDivisor(void){
	int x, y;
	int commonDivisor;
	while(scanf("%d %d", &x, &y) != EOF){
		if(x > 0 && y > 0){
			commonDivisor = gcd(x, y);
			printf("%d %d = %d\n", x, y, commonDivisor);
			printf("%d/%d = %d and %d/%d = %d\n",
				x, commonDivisor, (x/commonDivisor),
				y, commonDivisor, (y/commonDivisor)); 
			break;
		}
	}
}

///
#define N 1000
void primeNumbers(void){
	int i, j, a[N+1];
	
	// populating the array
	for(a[1] = 0, i = 2; i <= N; i++){
		a[i] = 1; // 1 = means number is prime
	}

	for(i = 2; i <= N/2; i++){
		for(j = 2; j <= N/i; j++){
			a[i * j] = 0; // 0 means number is not prime
		}
	}

	// print prime numbers
	for(i = 1; i <= N; i++){
		if(a[i]){
			printf("%4d", i);
		}
	}
	printf("\n");
}

int main(){
	time_t biggest = 0x7FFFFFFF;
	printf("biggest = %s \n", asctime(gmtime(&biggest)));
	//getGreatestCommonDivisor();
	primeNumbers();
	return 0;
}
