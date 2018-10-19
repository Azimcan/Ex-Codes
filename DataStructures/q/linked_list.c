#include <stdio.h>
#include <stdlib.h>

struct n{
	int x;
	struct n* next;
};

typedef struct n node;

void add(node* iter);
void print(node* iter);
void bwAdd(node* iter, int x, int addingNumb);
node* addShort(node* r, int x);

int main(){
	node* root;
	/*
		Buraya kadar bağlı liste için 
	gerekenler ve ilk düğüm oluştu.
	*/
	root = NULL;
	root = addShort(root,	400);
	root = addShort(root,	40);
	root = addShort(root,	4);
	root = addShort(root,	450);
	root = addShort(root,	50);
	print(root);

	/*
	add(root);
	print(root);
	printf("-----------------\n");
	bwAdd(root, 2, 50);
	print(root);
	*/

	return(0);
}

node* addShort(node* r, int x){
	if(r == NULL){//Linked list boş.
		r = (node*)malloc(sizeof(node));
		r->next = NULL;
		r->x = x;

		return r;
	}
	else if(r->x > x){//İlk elemandan küçük o halde root değişmeli.
		node* temp = (node*)malloc(sizeof(node));
		temp->x = x;
		temp->next = r;

		return temp;
	}
	node* iter = r;
	while(iter->next != NULL && iter->next->x < x){
		iter = iter->next;
	} 
	node* temp = (node*)malloc(sizeof(node));
	temp->next = iter->next;
	iter->next = temp;
	temp->x = x;

	return r;
}

void bwAdd(node* iter, int x, int addingNumb){
	for(int i=0; i<x; i++){
		iter = iter->next;
	}
	
	node* temp = (node*)malloc(sizeof(node)); 
	temp->next = iter->next;
	iter->next=temp;
	
	temp->x = addingNumb;
}

void add(node* iter){
	for(int i=0; i<5; i++){
		iter->x = i*10;
		iter->next = (node*)malloc(sizeof(node));
		iter = iter->next;	
		iter->next = NULL;
	}
}
void print(node* iter){
	int i = 1;
	while(iter != NULL){
		printf("%d.eleman %d\n",i++, iter->x);
		iter = iter->next;
	}
}