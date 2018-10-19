#include <stdio.h>
#include <stdlib.h>

struct n{
	int data;
	struct n* next;
};
typedef struct n node;

node* push(node* root, int data);
node* mergeArray(node* array, node* first, int pivot, node* second);
int size(node* root);
int eleman(node* array, int indis);
void swap(node* first, node* second);
void print(node* root);

node* quickSort(node* array);
int radixSort(int array[]);

int main(){
	node* array = NULL;

	array = push(array, 170);
	array = push(array, 45);
	array = push(array, 75);
	array = push(array, 90);
	array = push(array, 2);
	array = push(array, 80);
	array = push(array, 802);
	array = push(array, 66);
	array = push(array, 85);
	array = push(array, 91);
/*
	for (int i = 0; i < SIZE; i++){
		printf("%d.eleman: ", i+1);
		scanf("%d", &array[i]);
	}
*/

	print(quickSort(array));

	return 0;
}

node* push(node* root, int data){
	if(root == NULL){
		root = (node*)malloc(sizeof(node));
		root->data = data;
		root->next = NULL;

		return root;
	}
	node* iter = root;
	while(iter->next != NULL){
		iter = iter->next;
	}

	node* temp = (node*)malloc(sizeof(node));
	temp->data = data;
	temp->next = NULL;
	iter->next = temp;
	
	return root;
}

node* mergeArray(node* array, node* first, int pivot, node* second){
	node* iter = array;
	while(first != NULL){
		iter->data = first->data;
		first = first->next;
		iter = iter->next;
	}
	iter->data = pivot;
	while(second != NULL){
		iter->data = second->data;
		second = second->next;
		iter = iter->next;
	}
	return array;
}

int size(node* root){
	int count = 0;

	while(root != NULL){
		count++;
		root = root->next;
	}
	return count;
}

int eleman(node* array, int indis){
	for(int i = 0; i < indis; ++i){
		array = array->next;
	}
	return array->data;
}

void print(node* root){
	while(root != NULL){
		printf("%d ", root->data);
		root = root->next;
	}
	printf("\n");
}

node* quickSort(node* array){
	if(size(array) <= 1)
		return array;
	
	node* leftArray = NULL;
	node* rightArray = NULL;
	
	int pivot = eleman(array, size(array)/2);
	printf("-----------------------------------\n");
	printf("-> %d\n", pivot);

	node* iter = array;
	while(iter != NULL && size(array) != 1){
		if(iter->data < pivot){
			leftArray = push(leftArray, iter->data);
			iter = iter->next;
			printf("left\n");
		}
		else if(iter->data > pivot){
			rightArray = push(rightArray, iter->data);
			iter = iter->next;
			printf("right\n");
		}
		else if(iter->data == pivot){
			iter = iter->next;
		}
	}

	printf("\narray: ");
	print(array);
	printf("\n");

	printf("left: ");
	print(leftArray);
	printf("\n");

	printf("pivot: ");
	printf("%d\n", pivot);
	printf("\n");

	printf("right: ");
	print(rightArray);
	printf("\n");
		
	return mergeArray(array, quickSort(leftArray), pivot, quickSort(rightArray));;
}

int radixSort(int array[]){
	
}