#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

void swap(int* a, int* b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void insertion(int* array, int data, int index){
	if(index == SIZE){
		printf("Heap dolu\n");
	}
	else{
		array[index] = data;
		while(index != 1 && array[index/2] < array[index]){
			swap(&array[index/2], &array[index]);
			index /= 2;
		}
	}
}

int deletion(int* array){
	int max;
	int index = 1;
	
	if(array[index] == 0){
		printf("Heap boş\n");
		return 0;
	}
	else{
		max = array[index];
		// array[i] = array[index-1];
		array[index] = 0;
		while(array[index] < array[2*index] || array[index] < array[2*index+1]){
			if(array[2*index] > array[2*index+1]){
				swap(&array[2*index], &array[index]);
				index *= 2;
			}
			else{
				swap(&array[2*index+1], &array[index]);
				index = 2*index+1;
			}
		}
		return max;
	}
}

void print(int* array){
	for (int i = 1; i < SIZE; i++){
		printf("%d  ", array[i]);
	}
	printf("\n");
}
/*
	yazılan ıkı fonksıyonu kullanarak butun kod halıne getir.
	basıt arayuz oluştur
	swap fonksıyonu yaz
	prınt fonksıyonu yaz
*/