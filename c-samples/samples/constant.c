#include <stdio.h>
#include <stdlib.h>

int main(void){
	int number1 = 10;
	int number2 = 20;

	int * number1Pointer = &number1;
	int * const constNumber2Pointer = &number2;

	printf("Value of number1: %d\n", *number1Pointer);
	printf("Value of number2 : %d\n\n", *constNumber2Pointer); 

	*number1Pointer += 10;
	*constNumber2Pointer += 10;

	printf("Value of number1 : %d\n", *number1Pointer);
	printf("Value of number2 : %d\n\n", *constNumber2Pointer);

	const int *number2Pointer = &number2;

	number2Pointer = number1Pointer;

	printf("Value of number2 : %d\n", *number2Pointer);

	return 0; 
}