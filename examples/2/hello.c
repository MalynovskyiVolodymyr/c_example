#include <stdio.h>
#include <stdlib.h>

void swap(int*, int*);

void simple(void){
	int a = 21;
	int b = 17;

	swap(&a, &b);
	printf("simple: a=%d, b=%d\n", a, b);
}
//

void static_variable(void){
	static int value = 0;
	value++;
	printf("%d value\n", value);	
}

void simple1(void){
	for(int i=0; i < 5; i++){
		static_variable();
	}
}

int old_main(void){
	//puts("Hello world!");
	simple1();
	return EXIT_SUCCESS;
}

void swap(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}
////
#include <string.h>

typedef struct {
	int signum;
	char signame[20];
	char sigdesc[100];
}sigrecord;


void simple_sample(void){
	sigrecord record;
	
	record.signum = 5;
	strcpy(record.signame, "SIGINT");
	strcpy(record.sigdesc, "Interrupt from keyboard");

	printf("simple structure record:\n signum=%d\n signame=%s\n sigdesc=%s\n",record.signum, record.signame, record.sigdesc);

	sigrecord *record_p = &record;
	record_p->signum = 111;
	strcpy(record_p->signame, "Hello!");
	strcpy(record_p->sigdesc, "Hello description");
	printf("---------------------------\nsimple structure pointer record_p:\n signum=%d\n signame=%s\n sigdesc=%s\n", record_p->signum, record_p->signame, record_p->sigdesc);

}

union{
	struct{
		int type;
	} n;
	struct{
		int type;
		int intnode;
	} ni;
	struct{
		int type;
		double doublenode;
	} nf;
}my_union;

void simple_union(void){
	// union can 1 at time
	my_union.nf.type = 1;
	my_union.nf.doublenode = 3.14;
	printf("my_union contains:\n type=%d\n doublenode=%.2f\n", my_union.nf.type, my_union.nf.doublenode);
}
////////////
// restict -- ensures that pointers are different objects
///////////
void restrict_example(unsigned int n, int * restrict p, int * restrict q){
	while(n-- > 0){
		*p++ = *q++;
	}
}

void old_main1(void){
	simple_sample();
	simple_union();
	
	int a[10];
	int b[] = {1,2,3,4,5,6,7,8,9};
	restrict_example(10,a,b);	
}
//////////////
#include <limits.h>
void simple_1(void){
	unsigned int ui = UINT_MAX;
	ui++;
	printf("ui = %u\n", ui);
	ui--;
	printf("ui = %u\n", ui);
}

#define Abs(i, flag) ((i) >= 0 ? (i) : ((i) == (flag) ? (flag) : -(i)))

void simple_2(void){
	int si = -25;
	int abs_si = Abs(si, INT_MIN);
	printf("%d\n", abs_si);
}

void simple_3(void){
	unsigned int ui = UINT_MAX;
	signed char c = -1;

	if(ui == c){
		printf("-1 equals %u\n", ui);
	}

	signed char c1;
	int i1 = INT_MAX;
	long k;
	k = (c1 = i1);
	printf("k = %d\n", k);
}

//////////

int f(void){
	return 0;
}

void g(int (*func)(void)){
	if(func() != 0){
		printf("g failes!\n");
	}else{
		printf("------------------\n");
	}
}

void simple_4(){
	g(f);
}

//////////

void simple_5(){
	char abc[] = "abc";
	char xyz[] = "xyz";
	char *p = abc;
	
	printf("%c\n", ++*p);	
	p = xyz;
	printf("%c\n", *p++);
}

#include<stdbool.h>

bool is_odd(int n){
	return n %2 != 0;
}

void simple_6(void){
	int numbers[] = {1,2,3,4,5,6,7,8,9};

	for(int i = 0; i < sizeof(numbers)/sizeof(numbers[0]); i++){
		if(is_odd(i)){
			printf("number %d is odd\n", i);
		}else{
			printf("number %d is even\n", i);
		}
	}
}

void simple_7(void){
	int arr[100];
	for(int i=0; i < sizeof(arr)/sizeof(arr[0]); i++){
		arr[i]=i;
	}
	int *arrp1 = &(arr[50]);
	int *arrp2 = arrp1 + 30;
	printf("%td\n", arrp2 - arrp1);
}

////////
typedef enum { Savings, Checking, MoneyMarket } AccountType;

void enum_test(AccountType account){
	double interest_rate = 0;
	
	switch(account){
		case Savings:
			interest_rate = 3.0;
			break;
		case Checking:
			interest_rate = 1.0;
			break;
		case MoneyMarket:
			interest_rate = 4.5;
			break;
		default:
			interest_rate = 0;
			break;
	}

	printf("Interest rate = %g.\n", interest_rate);
	
	printf("enum value = %d.\n", account);
}

void simple_8(void){
	AccountType test = MoneyMarket;
	enum_test(test);
}
///////////////
typedef struct{
	char c[10];
	int i;
	double d;
} widget;

void simple_9(void){
	widget *p = malloc(sizeof(widget));
	if(p == NULL){
		printf("cannot allocate widget\n");
		return;
	}
	p->c[0] = 10;
	p->c[1] = 20;
	printf("widget was allocated with values c array size = %d\n", sizeof(p->c));
	widget w = {"abc", 9, 3.2};
	
	free(p);
	memcpy(p, &w, sizeof(widget));	

	printf("second widget p->i=%d\n", p->i);
	printf("w.i=%d\n", w.i);
	free(p);	
	printf("w.i=%d\n", w.i);
	
}

int simple_10(){
	char *str = (char *) malloc(16);
	
	if(str){
		strncpy(str, "123456789abcdef", 15);
		str[15] = '\0';
		printf("str = %s\n", str);
		free(str);
		return EXIT_SUCCESS;
	}
	return EXIT_FAILURE;
}

void simple_11(void){
	int *p2;
	int *p = malloc(100*sizeof(int));	
	
	for(int i = 1; i < 100; i++){
		p[i]=i;
	}
	
	printf("memory was allocated size = %d\n", sizeof(p));
	size_t size = 150*sizeof(int); // incrising size +50
	if((p2 = realloc(p, size)) == NULL){
		free(p);
		printf("an error cannot allocate the memmory\n");
	}else{
		p = p2;
		p[120] = 1111111;
		printf("memory was reallocated size = %d\n", (sizeof(p[0])*150));
		printf(" p[120] = %d\n", p[120]);
		free(p);
	}
}
///////
typedef struct{
	size_t num;
	int data[];	
} widget2;

void simple_12(void){
	size_t array_size = 35;
	widget2 *p = (widget2 *) malloc(sizeof(widget2) + sizeof(int)*array_size);
	if(p == NULL){
		return;
	}

	p->num = array_size;
	for(size_t i=0; i < p->num; ++i){
		p->data[i] = 17;
	}
	free(p);
}

#include<ctype.h>

void simple_13(void){
	char c = 'c';
	if(isdigit(c)){
		printf("value is digit %d\n", c);
	}else if(isalpha(c)){
		printf("value is character %c\n", c);
	}
}

void main(void){
	simple_1();
	simple_2();
	simple_3();
	simple_4();
	simple_5();
	simple_6();
	simple_7();
	simple_8();
	simple_9();
	simple_10();
	simple_11();
	simple_12();
	simple_13();
}



