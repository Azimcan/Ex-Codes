#include <stdio.h>
#include <stdlib.h>
#include "linked_stack.h"

int pop(node* root){
	if(root == NULL){
		printf("Stack boş!!\n");
		return -1;
	}

	if(root->next == NULL){
		int rvalue = root->data;
		free(root);
		return rvalue;
	}

	node* iter = root;
	while(iter->next->next != NULL){
		iter = iter->next;
	}

	node* temp = iter->next;
	int rvalue = temp->data;
	iter->next = NULL;
	free(temp);
	return rvalue;
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
		printf("%d\n", root->data);
		root = root->next;
	}
}

