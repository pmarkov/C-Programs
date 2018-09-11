#include <stdio.h>
#include <stdlib.h>

#define MAX 50

struct BST {
	char data;
	struct BST *left;
	struct BST *right;
};

struct BST *insert_struct(struct BST *root, char data);
struct BST *new_node(char data);
void free_struct(struct BST *ptr);

/*Depth-first traversal*/
void preorder_print(struct BST *ptr);
void inorder_print(struct BST *ptr);
void postorder_print(struct BST *ptr);

/*Breadth-first traversal*/
void levelorder_print(struct BST *ptr);
struct BST *arr[MAX];
int front = -1, rear = -1;
char isEmpty();
char isFull();
void Enqueue(struct BST *ptr);
void Dequeue();

int main()
{
	struct BST *root = NULL;

	root = insert_struct(root, 'F');
	root = insert_struct(root, 'D');
	root = insert_struct(root, 'B');
	root = insert_struct(root, 'A');
	root = insert_struct(root, 'C');
	root = insert_struct(root, 'E');
	root = insert_struct(root, 'J');
	root = insert_struct(root, 'G');
	root = insert_struct(root, 'I');
	root = insert_struct(root, 'H');
	root = insert_struct(root, 'K');

	printf("Preorder traversal: ");
	preorder_print(root);
	printf("\n\nInorder traversal: ");
	inorder_print(root);
	printf("\n\nPostorder traversal: ");
	postorder_print(root);

	printf("\n\nLever-order traversal: ");
	levelorder_print(root);
	free_struct(root);

	getchar();
	return 0;
}
struct BST *insert_struct(struct BST *root, char data)
{
	if (!root) {
		root = new_node(data);
	}
	else if (data <= root->data) {
		root->left = insert_struct(root->left, data);
	}
	else {
		root->right = insert_struct(root->right, data);
	}
	return root;
}
struct BST *new_node(char data)
{
	struct BST *p = (struct BST *)malloc(sizeof(struct BST));
	p->data = data;
	p->left = NULL;
	p->right = NULL;
	return p;
}
void free_struct(struct BST *ptr)
{
	if (ptr->left) {
		free_struct(ptr->left);
	}
	if (ptr->right) {
		free_struct(ptr->right);
	}
	free(ptr);
	return;
}
void preorder_print(struct BST *ptr)
{
	if (ptr) {
		printf("%c ", ptr->data);
		preorder_print(ptr->left);
		preorder_print(ptr->right);
	}
}
void inorder_print(struct BST *ptr)
{
	if (ptr) {
		inorder_print(ptr->left);
		printf("%c ", ptr->data);
		inorder_print(ptr->right);
	}
}
void postorder_print(struct BST *ptr)
{
	if (ptr) {
		postorder_print(ptr->left);
		postorder_print(ptr->right);
		printf("%c ", ptr->data);
	}
}
/*********************************************************/
void levelorder_print(struct BST *root)
{
	if (!root)
		return;
	Enqueue(root);
	while (!isEmpty()) {
		struct BST *current = arr[front];
		Dequeue();
		printf("%c ", current->data);
		if (current->left) {
			Enqueue(current->left);
		}
		if (current->right) {
			Enqueue(current->right);
		}
	}
}
char isEmpty()
{
	return (front == -1 && rear == -1) ? 1 : 0;
}
char isFull()
{
	return (rear + 1) % MAX == front ? 1 : 0;
}
void Enqueue(struct BST *ptr)
{
	if (isFull()){
		printf("The queue is full");
		return;
	}
	else if (isEmpty()){
		front = rear = 0;
		arr[rear] = ptr;
	}
	else {
		arr[++rear] = ptr;
	}
}
void Dequeue()
{
	if (isEmpty()) {
		printf("The queue is empty");
		return;
	}
	else if (front == rear) {
		front = rear = -1;
	}
	else {
		front = (front + 1) % MAX;
	}
}