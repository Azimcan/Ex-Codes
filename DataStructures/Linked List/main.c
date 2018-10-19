#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main(){
	node* root = NULL;

	root = push(root, 10);
	root = push(root, 20);
	root = push(root, 30);
	root = push(root, 40);
	root = push(root, 50);

	print(root);


	return 0;
}