#ifndef avl
#define avl
	struct n{
		int data;

		struct n* left;
		struct n* right;
		int height;
	};
	typedef struct n avlTree;

	avlTree* rightRotate(avlTree*);
	avlTree* leftRotate(avlTree*);
	avlTree* leftrightRotate(avlTree*);
	avlTree* insertToAvl(avlTree*, int);
	
	int maxValue(int, int);
	int height(avlTree*);

#endif