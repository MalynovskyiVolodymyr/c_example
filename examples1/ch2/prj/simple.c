#include <stdio.h>
#include <math.h>
#include "gd.h"

int main(){
	double x = get_double("enter the x value: ", -100, 100);
	double y = get_double("enter the y value: ", -100, 100);

	double d = sqrt(pow(x,2) + pow(y,2));

	printf("Distance is %lf meters\n", d);
}
