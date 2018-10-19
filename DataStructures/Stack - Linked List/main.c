#include <stdio.h>
#include <stdlib.h>
#include "linked_stack.h"

int main(){
	node* s = NULL;

	s = push(s, 10);
	s = push(s, 20);
	s = push(s, 30);
	s = push(s, 40);
	print(s);
	printf("\n");
	
	printf("->%d\n", pop(s));
	printf("->%d\n", pop(s));
	printf("->%d\n", pop(s));
	printf("->%d\n", pop(s));
	printf("->%d\n", pop(s));
	printf("\n");

	print(s);

	return 0;
}