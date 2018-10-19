#ifndef trees
#define trees
	struct n{
		int data;
		struct n* left;
		struct n* right;
	};
	typedef struct n node;

	node* insert(node*, int);
	int search(node*, int);
	void travel(node*);
	int min(node*);
	int max(node*);
	node* deletion(node*, int);

#endif