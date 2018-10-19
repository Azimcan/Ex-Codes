#include <stdio.h>
#include <stdlib.h>

#include "functions.h"

node* insertionSort(node* root, int size){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if(root >= root->next)
				swapNode(root, root->next);
		}
	}
	return root;
}


node* swapNode(node* nodeFirst, node* nodeSecond){
	node* temp;

	temp = nodeSecond->next;
	nodeFirst->next = temp;
	nodeSecond = nodeFirst;
}

int size(node* root){
	int size = 0;
	if(root == NULL){
		printf("Dizi boş...\n");
		return 0;
	}

	while(root != NULL){
		root = root->next;
		size++;
	}
	return size;
}

node* addData(node* root, int data){
	if( root == NULL ){
		root = (node*)malloc(sizeof(node));
		root->data = data;
		root->next = NULL;
		return root;
	}
	node* iter = root;
	while(iter->next != NULL)
		iter = iter->next;

	node* temp = (node*)malloc(sizeof(node));
	temp->data = data;
	temp->next = NULL;
	iter->next = temp;

	return root;
}

void print(node* root){
	while(root != NULL){
		printf("%d  ", root->data);
		root = root->next;
	}
	printf("\n");
}