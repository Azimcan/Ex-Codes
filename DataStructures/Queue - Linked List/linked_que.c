#include <stdio.h>
#include <stdlib.h>
#include "linked_que.h"

int que = 0;
int headofque = 0;
node* end = NULL;

node* enque(node* root, int data){
	if(root == NULL){
		root = (node*)malloc(sizeof(node));
		root->data = data;
		root->next = NULL;
		end = root;

		return root;
	}
	else{
		end->next = (node*)malloc(sizeof(node));
		end->next->data = data;
		end = end->next;
		end->next = NULL;

		return root;
	}
}

int deque(node* root){
	if(root = NULL){
		printf("Sıra boş\n");
		return -1;
	}
	int rvalue = root->data;
	node* temp = root;
	root = root->next;
	free(temp);

	return rvalue;
}

void print(node* root){
	while(root != NULL){
		printf("%d\n", root->data);
		root = root->next;
	}
}
