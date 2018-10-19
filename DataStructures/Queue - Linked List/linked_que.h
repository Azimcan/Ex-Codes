#ifndef linked_que
#define linked_que
	struct n{
		int data;
		struct n* next;

	};
	typedef struct n node;

	node* enque(node*, int);
	int deque(node*);
	void print(node*);
#endif