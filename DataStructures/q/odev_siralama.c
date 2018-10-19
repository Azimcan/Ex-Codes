#include <stdio.h>
#include <stdlib.h>

struct n{
	int data;
	struct n* next;
};

typedef struct n node;

//Fonksiyon tanımları
node* addShort(node* root, int data);
node* delete(node* root, int data);
void print(node* root);

int main(){
	node* root = NULL;
	root = addShort(root, 100);
	root = addShort(root, 400);
	root = addShort(root, 400);
	root = addShort(root, 400);
	root = addShort(root, 400);
	root = addShort(root, 400);
	root = addShort(root, 700);

	print(root);
	printf("-------------\n");
	delete(root, 400);
	print(root);

	return 0;
}

//Sıralı ekleme fonksiyonu
node* addShort(node*root, int data){
	if(root == NULL){
		root = (node*)malloc(sizeof(node));
		root->next = NULL;
		root->data = data;

		return root;
	}
	if(root->data < data){
		node* temp = (node*)malloc(sizeof(node));
		temp->data = data;
		temp->next = root;

		return temp;
	}
	node* iter = root;
	while(iter->next != NULL && iter->next->data > data){
		iter = iter->next;
	}
	node* temp = (node*)malloc(sizeof(node));
	temp->next = iter->next;
	iter->next = temp;
	temp->data = data;

	return root;
}

node* delete(node* root, int data){
	node* temp;
	node* iter = root;
	
	if(root->data == data){
		temp = root;
		root = root->next;
		free(temp);
	}

	while(iter->next != NULL && iter->next->data != data){
		iter = iter->next;
	}

	while(iter->next->data == data){
		temp = iter->next;
		iter->next = iter->next->next;
		free(temp);
		
		if(iter->next->next == NULL && iter->next->data == data){
			temp = iter->next;
			free(temp);
		}
		else if(iter->next != NULL && iter->next->data != data){
			iter = iter->next;
		}
	}

	if(iter->next == NULL){
		printf("Sayı bulunamadı.");
	}

	return root;
}





//Ekran bastırma fonksiyonu
void print(node* root){
	int x = 0;
	while(root != NULL){
		printf("%d. sayı %d\n", ++x, root->data);
		root = root->next;
	}
}