#ifndef linked_list
#define linked_list
	struct n{
		int data;
		struct n* next;
	};
	typedef struct n node;

	void btwAdd(node*, int, int);
	node* push(node*, int);
	void print(node*);
#endif