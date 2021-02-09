#include <stdio.h>
#include <stdlib.h>

int main(){
	int *x;
	int *y;

	x = malloc(sizeof(int));
	*x = 42;
	y = x;

	printf("x points to: %i\n", *x);
	printf("y points to: %i\n", *y);
}