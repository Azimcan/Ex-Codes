#include <stdio.h>
#include <stdlib.h>
#include "trees.h"

int main(){
	node* tree = NULL;
	tree = insert(tree, 8);
	tree = insert(tree, 4);
	tree = insert(tree, 2);
	tree = insert(tree, 1);
	tree = insert(tree, 3);
	tree = insert(tree, 6);
	tree = insert(tree, 5);
	tree = insert(tree, 7);
	tree = insert(tree, 12);
	tree = insert(tree, 10);
	tree = insert(tree, 9);
	tree = insert(tree, 11);
	tree = insert(tree, 14);
	tree = insert(tree, 13);
	tree = insert(tree, 15);

	travel(tree);
	printf("Arama sonucu: %d\n", search(tree, 16));

	printf("Tree'deki minumum değer: %d\n", min(tree));
	printf("Tree'deki maksimum değer: %d\n", max(tree));
	
	deletion(tree, 10);
	travel(tree);
	return 0;
}