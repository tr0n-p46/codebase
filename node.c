#include <stdio.h>

typedef struct Node {
	int val;
	struct Node* rightChild;
	struct Node* leftChild;	
}Node;

typedef struct BST {
	int nodeCount;
	struct Node* root;
}BST;

void insert(BST* b,int val) {
	Node n;
	n.val=val;
	n.leftChild = NULL;
	n.rightChild = NULL;
	if(b == NULL) {
		b->nodeCount = 1;
		b->root = &n;		
	}
	else {
		if(b)	
	}
}

bool find(BST* b,int val) {
}

void delete(BST* b,int val) [
}

int main() {

}
