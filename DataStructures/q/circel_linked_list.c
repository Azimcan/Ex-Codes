#include <stdio.h>
#include <stdlib.h>

struct n{
	int data;
	struct n* next;
};

typedef struct n node;

void print(node* root);
void add(node* root, int data);
node* addShort(node* root, int data);

int main(){
	node* root = NULL;
	root = addShort(root, 100);
	root = addShort(root, 400);
	root = addShort(root, 300);
	root = addShort(root, 600);
	root = addShort(root, 400);
	root = addShort(root, 800);
	root = addShort(root, 700);

	print(root);

	return 0;
}

node* addShort(node* root, int data){
	
	if(root == NULL){//Linked list boş ise...
		root = (node*)malloc(sizeof(node));
		root->next = root;
		root->data = data;

		return root;
	}
	else if(root->data > data){//"data" ilk elemandan küçük o halde root değişmeli.
		node* temp = (node*)malloc(sizeof(node));
		temp->data = data;
		temp->next = root;
		
		node* iter;
		while(iter->next != root){
			iter = iter->next;
			iter->next = temp;
			return temp;
		}
		return temp;
	}

	node* iter = root;
	while(iter->next != root && iter->next->data < data){
		iter = iter->next;
	} 
	node* temp = (node*)malloc(sizeof(node));
	temp->next = iter->next;
	iter->next = temp;
	temp->data = data;

	return root;
}

void add(node* root, int data){
	node* iter = root;
	while(iter->next != root){
		iter = iter->next;
		iter->next = (node*)malloc(sizeof(node));
		iter->next->data = data;
		iter->next->next = root;
	}
}

void print(node* root){
	int x = 1;
	node* iter = root->next;

	printf("%d. sayı %d\n", x, iter->data);

	while(iter != root){
		printf("%d. sayı %d\n", ++x, root->data);
		iter = iter->next;
	}
}