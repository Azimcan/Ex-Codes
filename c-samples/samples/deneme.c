#include <stdio.h>
#include <stdlib.h>

int main(void){
	int a = 15;
	int *q = &a;
	
	int *p = 10;

	printf("%d\n", *q);

	printf("%d\n", p);
}