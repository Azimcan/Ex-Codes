#include <stdio.h>
#include <stdlib.h>

struct n{
	int data;x
	struct n* next;
	struct n* prev;
};

typedef struct n node;


node* addShort(node* root, int data);
node* delete(node* root, int data);

void add(node* iter);
void print(node* iter);

int main(){
	node* root;

	root = NULL;
	root = addShort(root, 400);
	root = addShort(root, 40);
	root = addShort(root, 4);
	root = addShort(root, 450);
	root = addShort(root, 50);

	print(root);

	return(0);
}

node* addShort(node* root, int data){
	if(root == NULL){//Linked list boş is ...
		root = (node*)malloc(sizeof(node));
		root->next = NULL;
		root->prev = NULL;
		root->data = data;

		return r;
	}
	
	else if(r->data > data){//İlk elemandan küçük o halde root değişmeli.
		node* temp = (node*)malloc(sizeof(node));
		temp->data = data;
		temp->next = root;

		return temp;
	}
	node* iter = root;
	while(iter->next != NULL && iter->next->data < data){
		iter = iter->next;
	} 
	node* temp = (node*)malloc(sizeof(node));
	temp->next = iter->next;
	iter->next = temp;
	temp->data = data;

	return root;
}
	
node* delete(node* root, int data){

}
	
void add(node* iter){
	for(int i=0; i<5; i++){
		iter->data = i*10;
		iter->next = (node*)malloc(sizeof(node));
		iter = iter->next;	
		iter->next = NULL;
	}
}
void print(node* iter){
	int i = 1;
	while(iter != NULL){
		printf("%d.eleman %d\n",i++, iter->data);
		iter = iter->next;
	}
}
