#ifndef linked_stack
#define linked_stack
	struct n{
		int data;
		struct n* next;
	};
	typedef struct n node;

	int pop(node*);
	node* push(node*, int);
	void print(node*);
#endif