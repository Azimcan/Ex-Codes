#ifndef functions
#define functions
// Linked List tanımlama
struct n{
	int data;
	struct n* next;
};
typedef struct n node;
// =========== END ========= 


node* insertionSort(node*, int);
node* swapNode(node*, node*);

node* addData(node*, int);
void print(node*);
int size(node*);

#endif