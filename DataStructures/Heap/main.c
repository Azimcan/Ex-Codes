#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main(){
	int* array = (int*)malloc(sizeof(int) * SIZE);
	
	int data = 10;

	for(int i = 1; i < SIZE; i++){
		insertion(array, data, i);
		print(array);
		data += 5; 
	}
	
	for(int i = 1; i < SIZE; i++){
		printf("->%d\n", deletion(array));
	}

/*
	printf("->%d\n", deletion(array, 15));
	print(array);
	printf("->%d\n", deletion(array, 14));
	print(array);
*/
	return 0;
}

/*
	Heapten 1
	avl tree 1
	cıktı sorusu 1
*/