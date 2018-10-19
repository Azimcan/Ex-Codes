#include <stdio.h>
#include <stdlib.h>
#include "linked_que.h"

int main(){
	node* root = NULL;
	root = enque(root, 40);
	root = enque(root, 20);
	root = enque(root, 30);
	root = enque(root, 60);
	print(root);

	printf("->%d\n", deque(root));
	
	return 0;
}

