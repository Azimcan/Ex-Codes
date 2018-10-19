#include <stdio.h>
#include <stdlib.h>

void findMax(int *numbersPointer);

int main(void){
	int *numbersPointer;

	for(int i = 0; i < 10; i++){
		int temp;
		printf("Number %d :", i+1);
		scanf("%d", &temp);
		*(numbersPointer + i) = temp;
	}
	printf("\n");

	findMax(numbersPointer);

	return 0;
}

void findMax(int *numbersPointer){
	int max = *numbersPointer;
	
		for(int i = 1; i < 10; i++){
			
			if(*(numbersPointer + i) > max){
				max = *(numbersPointer + i);
			}	
		}
		printf("Maximum values : %d\n", max);
}
