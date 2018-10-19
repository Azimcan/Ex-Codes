#include <stdio.h>
#include <stdlib.h>

struct n{
	int data;
	struct n* next;
};
typedef struct n node;

void add(node* root, int data);
void print(node* root);

int main(){
	node* root;
    root = NULL;
	add(root, 100);
	print(root);
	
	return 0;
}

void add(node* root, int data){
	node* iter = root;
	while(iter != NULL){
		iter = iter->next;
	}
	iter = (node*)malloc(sizeof(node));
	iter->data = data;
}

void print(node* root){
	node* iter = root;
	int i = 0;
	while(iter != NULL){
		printf("%d. eleman %d\n", i, iter->data);
		iter = iter->next;
	}
}

