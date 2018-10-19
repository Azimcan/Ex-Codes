#include <stdio.h>
#include <stdlib.h>

#include "functions.h"

int main(){
	node* root = NULL;
	
	root = addData(root, 5);
	root = addData(root, 6);
	root = addData(root, 8);
	root = addData(root, 7);
	root = addData(root, 4);
	root = addData(root, 9);

	print(root);
	
	printf("%d\n", size(root));

	root = insertionSort(root, size(root));

	print(root);
	return 0;
}