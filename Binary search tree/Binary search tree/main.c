#include <stdio.h>
#include <stdlib.h>

struct Tree {
	int data;
	struct Tree *left;
	struct Tree *right;
};

struct Tree *getNewNode(int num);
struct Tree *Insert(struct Tree *p, int num);
void Print(struct Tree *p);
short Search(struct Tree *p, int num);
int FindHeight(struct Tree *p);
int FindMin(struct Tree *p);
int FindMax(struct Tree *p);

int main()
{
	int height, min, max;

	struct Tree *root = NULL;
	root = Insert(root, 15);
	root = Insert(root, 10);
	root = Insert(root, 20);
	root = Insert(root, 12);
	root = Insert(root, 5);
	root = Insert(root, 25);

	height = FindHeight(root);
	printf("\nHeight is: %d\n\n", height);

	Print(root);
	min = FindMin(root);
	max = FindMax(root);
	printf("\n\nMinimum element is: %d\n", min);
	printf("Maximum element is: %d\n\n", max);

	int n, check;
	char ch;
	do {
		do {
			printf("\n\nEnter a number to be searched: ");
			check = scanf_s("%d", &n);
			while (getchar() != '\n');
		} while (!check);
		if (Search(root, n))
			printf("\nFound\n");
		else
			printf("\nNot Found\n");
		printf("\nFor exit - Ctrl/Z:");
		ch = getchar();
	} while (ch != EOF);

	return 0;
}
struct Tree *Insert(struct Tree *p, int num)

{
	if (!p)
		p = getNewNode(num);
	else if (num <= p->data)
		p->left = Insert(p->left, num);
	else
		p->right = Insert(p->right, num);
	return p;
}/*
{
	if (!p)
		p = getNewNode(num);
	else {
		struct Tree *temp = p;
		struct Tree *newNode = getNewNode(num);
		while (1)
		{
			if (num <= temp->data)
				while (num <= temp->data && temp->left != NULL)
					temp = temp->left;
			if (temp->left == NULL && num <= temp->data){
				temp->left = newNode;
				break;
			}
			if (num > temp->data)
				while (num > temp->data && temp->right != NULL)
					temp = temp->right;
			if (temp->right == NULL && num > temp->data){
				temp->right = newNode;
				break;
			}
		}
	}
	return p;
} */
struct Tree *getNewNode(int num)
{
	struct Tree *temp = (struct Tree*)malloc(sizeof(struct Tree));
	temp->data = num;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
void Print(struct Tree *p)
{
	if (p)
	{
		Print(p->left);
		printf("%d ", p->data);
		Print(p->right);
	}
}
short Search(struct Tree *p, int num)
{
	if (p == NULL)
		return 0;
	else if (p->data == num)
		return 1;
	else if (p->data >= num)
		return Search(p->left, num);
	else
		return Search(p->right, num);
}
int FindHeight(struct Tree *p)
{
	if (!p)
		return -1;
	return max(FindHeight(p->left), FindHeight(p->right)) + 1;
}
int FindMin(struct Tree *p)
{
	if (!p){
		printf("The tree is empty!");
		return -1;
	}
	if (!p->left) {
		return p->data;
	}
	else
		return FindMin(p->left);
}
int FindMax(struct Tree *p)
{
	if (!p) {
		printf("The tree is empty!");
		return -1;
	}
	if (!p->right)
		return p->data;
	else
		return FindMax(p->right);
}