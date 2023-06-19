#include <stdio.h>
#include <string.h>
#include <stdint.h>

struct {
	int Member1;
	int Member2;
}d1;

struct {
	int Member1: 3;
	int Member2: 3;	
}d2;

struct {
	unsigned char Member1: 3;
	unsigned char  :0;
	unsigned char Member3: 5;
}d3;
//
static const int COUNTER = 5;
struct simple{
	unsigned int a: 2;
	unsigned int b: 4;
	unsigned int c: 6;
}__attribute__((packed));

void simple_test(){	
	struct simple s;
	
	for(int i = 0; i < COUNTER; i++){
		s.a++; s.b++, s.c++;
		printf("s.a = %d, s.b = %d, s.c = %d\n", s.a, s.b, s.c); 
	}
	printf("size of struct simple = %d\n", sizeof(s));
}
/////////
/////////
/////////
uint64_t array_of_bits = 0;

#define SET_BIT(BF, N) BF |= ((uint64_t)0x0000000000000001 << N)
#define CLR_BIT(BF, N) BF &= ~((uint64_t)0x0000000000000001 << N)
#define IS_BIT_SET(BF, N) ((BF >> N) & 0x1)

void bits_fun(){
	SET_BIT(array_of_bits, 0);
	SET_BIT(array_of_bits, 2);
	SET_BIT(array_of_bits, 0);
	SET_BIT(array_of_bits, 7);
	SET_BIT(array_of_bits, 45);

	CLR_BIT(array_of_bits, 7);
	
	for(int i = 0; i < 64; i++){
		if(IS_BIT_SET(array_of_bits, i)){
			printf("+");
		}else{
			printf(".");
		}
	}
	printf("\n");

}

int main(){
	printf("Size of regular structure = %d\n", sizeof(d1));
	printf("Size of structure with Bit Field = %d\n", sizeof(d2));
	printf("Sizeof char bits structure = %d\n", sizeof(d3));
	d3.Member1 = 7;;	
	d3.Member3 = 31;
	printf("value int char 1 byte value1 = %d, value3 = %d\n",d3.Member1, d3.Member3);
	
	//simple_test();
	//bits_fun();
	return 0;
}



