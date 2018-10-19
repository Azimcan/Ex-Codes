#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

avlTree* rightRotate(avlTree* x){
	avlTree* temp = x->left;
	x->left = temp->right;
	temp->right = x;
	x->height = maxValue(height(x->left), height(x->right)) + 1;
	temp->height = maxValue(height(temp->left), height(temp->right));
	return temp;
}

avlTree* leftRotate(avlTree* x){
	avlTree* temp = x->right;
	x->right = temp->left;
	temp->left = x;
	x->height = maxValue(height(x->right), height(x->left)) + 1;
	temp->height = maxValue(height(temp->right), height(temp->left));
	return temp;
}

avlTree* leftrightRotate(avlTree* x){
	x->left = rightRotate(x->left);
	return leftRotate(x);	
}

avlTree* insertToAvl(avlTree* tree, int data){
	if(tree != NULL){
		if(data < tree->data){
			tree->left = insertToAvl(tree->left, data);
		}
		else if(data > tree->data){
			tree->right = insertToAvl(tree->right, data);
		}
		else{
			return tree;
		}
		tree->height = maxValue(height(tree->left), height(tree->right));	
	}
	if(height(tree->right) - height(tree->left) < -1 && data < tree->left->data){
		return rightRotate(tree);
	}
	else{
		tree = (avlTree*)malloc(sizeof(avlTree));
	}
}

int maxValue(int x, int y){
	if(x > y){
		return x;
	}
	else{
		return y;
	}
}

int height(avlTree* root){
	if(root == NULL){
		return -1;
	}
	else{
		int left_y, right_y;
		left_y = height(root->left);
		right_y = height(root->right);
		if(right_y > left_y){
			return right_y + 1;
		}
		else{
			return left_y + 1;
		}
	}
}

void print(avlTree* tree){
	for(int i = 0; i < 10; i++){
		printf("%d\n", tree->data);
	}
}


/*
sola dondurme
ıkılı dondurme
ekleme
silme
*/