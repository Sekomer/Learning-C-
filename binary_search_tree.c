#include <stdio.h>
#include <stdlib.h>

/*
*creating binary search tree nodes
	key => nodes value
	parent => node's parent's pointer
 	left => node's left child's pointer
 	right => node's right child's pointer
*/
typedef struct bnode {
	int key;
	struct bnode *parent;
	struct bnode *left;
	struct bnode *right;
} BNODE;

// function that returns BNODE pointer with n value
BNODE* new_node(int n)
{
	BNODE* bnode = malloc(sizeof(BNODE));
	bnode->key = n;
	bnode->parent = NULL;
	bnode->left = NULL;
	bnode->right = NULL;
	return	bnode;
}
// function that takes pointers of the root and node that we want to insert 
// inserts node to the tree
//@param *root => roots pointer
//@param *bnode => pointer of node that we will be inserted
// this function should be private  //
void
insert(BNODE *root, BNODE *bnode)
{
	BNODE *ptr = root;
	while (1) {
		if (bnode->key > ptr->key) {
			if (ptr->right != NULL)
				ptr = ptr->right;
			else {
				ptr->right = bnode;
				bnode->parent = ptr;
				break;
			}
		}
		else {
			if (ptr->left != NULL)
				ptr = ptr->left;
			else {
				ptr->left = bnode;
				bnode->parent = ptr;
				break;
			}
		}
	}
}

// function that creates new node and inserts its value
void
insert_key(BNODE *root, int value)
{
	BNODE *n = new_node(value);
	insert(root, n);
}

// prints the bst in order 
// in order traversal = in_order
void in_order(BNODE *bnode)
{
	if(bnode)
	{
		in_order(bnode->left);
			printf("%d\n", bnode->key);
		in_order(bnode->right);
	}
}
//deleting bst's
void free_node(BNODE *bnode)
{
	if(bnode->left) free_node(bnode->left);
	if(bnode->right) free_node(bnode->right);

	free(bnode);
}

int main()
{
	int a[] = {2,3,5,9,2,5,9,4,1};
	
	BNODE* root = new_node(5);
	int s = sizeof(a)/sizeof(*a);
	
	for (int i = 0; i < s; i++)
		insert_key(root, a[i]);
	
	in_order(root);
free_node(root);
return 0;
}