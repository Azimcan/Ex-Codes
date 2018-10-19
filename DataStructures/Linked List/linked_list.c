#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void btwAdd(node* root, int x, int data){
	
	node* iter = root;

	for(int i = 0; i < x; i++){
		iter = iter->next;
	}
	node* temp = (node*)malloc(sizeof(node));

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

void print(node* root){
	while(root != NULL){
		printf("-> %d\n", root->data);
		root = root->next;
	}
}