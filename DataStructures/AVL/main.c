#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int main(){
	avlTree* tree = (avlTree*)malloc(sizeof(avlTree));
	//tree = NULL;

	insertToAvl(tree, 10);
	/*
	insertToAvl(tree, 20);
	insertToAvl(tree, 30);
	insertToAvl(tree, 40);
	insertToAvl(tree, 50);
*/
	return 0;
}