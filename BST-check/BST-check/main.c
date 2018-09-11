#include <stdio.h>
#include <stdlib.h>

struct Tree {
	int data;
	struct Tree *left;
	struct Tree *right;
};

struct Tree *insert_node(struct Tree *root, int data);
struct Tree *new_node(int data);
struct Tree *delete_node(struct Tree *root, int data);
struct Tree *FindMin(struct Tree *ptr);
void print_struct(struct Tree *root);
void free_struct(struct Tree *root);

short IsBstUtil(struct Tree *root, int minVal, int maxVal);
short IsBinarySearchTree(struct Tree *root);

struct Tree *Getsuccessor(struct Tree *root, int data);
struct Tree *Find(struct Tree *root, int data);

int main()
{
	struct Tree *root = NULL;
	struct Tree *successor = NULL;
	int num;
	short check;

	root = insert_node(root, 10);
	root = insert_node(root, 5);
	root = insert_node(root, 15);
	root = insert_node(root, 20);
	root = insert_node(root, 25);
	root = insert_node(root, 0);
	check = IsBinarySearchTree(root);
	if (check) {
		printf("The tree is binary search tree.\n\n");
	}
	else {
		printf("The tree is not binary search tree.\n\n");
	}
	print_struct(root);

	successor = Getsuccessor(root, 5);

	printf("\n\nWhat number should be deleted?\n");
	scanf_s("%d", &num);
	while (getchar() != '\n');

	root = delete_node(root, num);
	print_struct(root);
	free_struct(root);

	getchar();
	return 0;
}
struct Tree *insert_node(struct Tree *root, int data)
{
	if (!root) {
		root = new_node(data);
	}
	else if (data <= root->data) {
		root->left = insert_node(root->left, data);
	}
	else {
		root->right = insert_node(root->right, data);
	}
	return root;
}
struct Tree *new_node(int data)
{
	struct Tree *ptr = (struct Tree *)malloc(sizeof(struct Tree));
	ptr->data = data;
	ptr->left = NULL;
	ptr->right = NULL;
	return ptr;
}
void print_struct(struct Tree *root)
{
	if (root) {
		print_struct(root->left);
		printf("%d ", root->data);
		print_struct(root->right);
	}
}
void free_struct(struct Tree *root)
{
	if (root->left) {
		free_struct(root->left);
	}
	if (root->right) {
		free_struct(root->right);
	}
	free(root);
}
short IsBstUtil(struct Tree *root, int minVal, int maxVal)
{
	if (!root)
		return 1;
	if (root->data >= minVal && root->data < maxVal
		&& IsBstUtil(root->left, minVal, root->data)
		&& IsBstUtil(root->right, root->data, maxVal))
		return 1;
	else
		return 0;
}
short IsBinarySearchTree(struct Tree *root)
{
	return IsBstUtil(root, INT_MIN, INT_MAX);
}
/*****************************************************/
struct Tree *delete_node(struct Tree *root, int data)
{
	if (!root)
		return root;
	else if (data < root->data) {
		root->left = delete_node(root->left, data);
	}
	else if (data > root->data) {
		root->right = delete_node(root->right, data);
	}
	else {				//The node to be deleted has been found.
		//Case 1: No child
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			root = NULL;
		}
		//Case 2: Only one child
		else if (root->left == NULL)
		{
			struct Tree *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			struct Tree *temp = root->left;
			free(root);
			return temp;
		}
		//Case 3: 2 children
		else {
			struct Tree *temp = FindMin(root->right);
			root->data = temp->data;
			root->right = delete_node(root->right, temp->data);
		}
	}
	return root;
}
struct Tree *FindMin(struct Tree *ptr)
{
	if (ptr->left)
	{
		ptr = FindMin(ptr->left);
	}
	return ptr;
}
/***************************************************/
struct Tree *Getsuccessor(struct Tree *root, int data)
{
	// Search the current node
	struct Tree *current = Find(root, data);
	if (current == NULL) {
		printf("The current node cannot be found.");
		return current;
	}
	//Case 1: Node has right subtree, we need to go to the leftmost node in the right subtree
	if (current->right != NULL) {	
		return FindMin(current->right);
	}
	//Case 2: No right subtree
	else {
		struct Tree *successor = NULL;
		struct Tree *ancestor = root;
		while (ancestor != current)
		{
			if (data < ancestor->data) 
			{
				successor = ancestor;	//for now this is the deepest node for which current node is in left
				ancestor = ancestor->left;
			}
			else
			{
				ancestor = ancestor->right;
			}
		}
		return successor;
	}
}
struct Tree *Find(struct Tree *root, int data)
{
	if (root != NULL && root->data != data) {
		if (data < root->data)
			root = Find(root->left, data);
		else
			root = Find(root->right, data);
	}
	return root;
}