#include <stdio.h>
#include <stdlib.h>
#include "trees.h"

node* insert(node* tree, int data){
	if(tree == NULL){
		node* root = (node*)malloc(sizeof(node));
		root->left = NULL;
		root->right = NULL;
		root->data = data;
		return root; 
	}
	if(tree->data >= data){
		tree->left = insert(tree->left, data);
		return tree;
	}
	else if(tree->data < data){
		tree->right = insert(tree->right, data);
		return tree;
	}
}

int search(node* tree, int data){
	if(tree == NULL){
		return -1;
	}
	else if(tree->data == data){
		return 1;
	}
	else if(search(tree->left, data) == 1){
		return 1;
	}
	else if(search(tree->right, data) == 1){
		return 1;
	}
	return -1;
}

void travel(node* tree){// LNR yaklaşımı...
	if(tree == NULL){
		return;
	}
	travel(tree->left);//Sol
	printf("%d\n", tree->data);//Node
	travel(tree->right);//Sağ
}

node* deletion(node* tree, int data){
	if(tree == NULL){
		return NULL;
	}
	if(tree->data == data){
		if(tree->left == NULL && tree->right == NULL){
			return NULL;
		}
		else if(tree->right != NULL){
			tree->data = min(tree->right);
			tree->right = deletion(tree->right, min(tree->right));
			return tree;
		}
		else{
			tree->data = max(tree->left);
			deletion(tree, (min(tree->right)));
			return tree;
		}
	}
	
	else if(tree->data < data){
		tree = deletion(tree->right, data);
		return tree;
	}
	
	else{
		tree = deletion(tree->left, data);
		return tree;
	}
}

int min(node* tree){
	while(tree->left != NULL){
		tree = tree->left;
	}
	return tree->data;
}

int max(node* tree){
	while(tree->right != NULL){
		tree = tree->right;
	}
	return tree->data;
}