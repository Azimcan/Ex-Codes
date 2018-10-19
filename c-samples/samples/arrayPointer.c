#include <stdio.h>
#include <stdlib.h>

void printIntegerArray(const int *array, int numberOfElements);
void printArray(const int ** arrayOfPointer, int sizeOfArrayPointer, int numberOfElements);

int main(void){
	int firstArray [] = {10, 11, 12, 100};
	int secondArray [] = {13, 14, 15, 100};
	int thirdArray [] = {17, 18, 19, 100};

	const int *arrayOfPointers [3] = {NULL};

	arrayOfPointers[0] = firstArray;
	arrayOfPointers[1] = secondArray;
	arrayOfPointers[2] = thirdArray;

	printIntegerArray(arrayOfPointers[0], 4);
	printf("\n");
	printIntegerArray(arrayOfPointers[1], 4);
	printf("\n");
	printIntegerArray(arrayOfPointers[2], 4);
	printf("\n\n");

	printArray(arrayOfPointers, 3, 4);

	return 0;
}

void printIntegerArray(const int *array, int numberOfElements){
	for(int counter = 0; counter < numberOfElements; counter++){
		printf("%-4d", *(array + counter));
	}
}

void printArray(const int **arrayOfPointer, int sizeOfArrayPointer, int numberOfElements){
	for(int counter = 0; counter < sizeOfArrayPointer; counter++){
		const int * currentArray = *(arrayOfPointer + counter);
		printIntegerArray(currentArray, numberOfElements);
		printf("\n");
	}
}
/*
Her gösterici (pointer) bir dizi olarak kabul edilebilir. Örneğin

int a[]
veya
int *a

aynı anlama gelmektedir ve tek boyutlu dizidir.

int a[][]
veya
int **a
veya
int *a[]

aynı anlama gelmektedir ve iki boyutlu dizi demektir. 
Aslında iki boyutlu dizi, her elemanı dizi olan dizidir ve her elemanı gösterici olan dizi olarak ifade edileibilir. 
Veya her elemanı gösterici olan bir diziyi gösteren gösterici de olabilir. 
Bu yüzden int **a tanımı iki boyutlu dizi anlamındadır.
*/