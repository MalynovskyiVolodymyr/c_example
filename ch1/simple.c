#include <stdio.h>
#include "simple.h"

#define PI 3.14159

typedef struct{
    int inval1;
    int inval2;
    int outval;
} MY_DATA;

void add(MY_DATA *d){
    d->outval = d->inval1 + d->inval2;
}

void temp(void){
    MY_DATA data;
    data.inval1 = 5;
    data.inval2 = 7;

    add(&data);
    printf("The sum of %d and %d is %d\n", data.inval1, data.inval2, data.outval);
}

void main(void){
    run_all();
    temp();
}
