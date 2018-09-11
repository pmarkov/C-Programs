#include <stdio.h>
#include <stdlib.h>

struct Node {
	struct Node *prev;
	int data;
	struct Node *next;
};

struct Node *getNewNode(int num);
struct Node *InsertAtHead(struct Node *p, int num);
struct Node *InsertAtEnd(struct Node *p, int num);
struct Node *Reverse(struct Node *headptr);
void Print(struct Node *p);
void ReversePrint(struct Node *p);

int main()
{
	struct Node *headptr = NULL;

	headptr = InsertAtHead(headptr, 5);
	headptr = InsertAtHead(headptr, 6);
	headptr = InsertAtHead(headptr, 7);
//	headptr = InsertAtEnd(headptr, 4);
//	headptr = InsertAtEnd(headptr, 3);
//	headptr = InsertAtEnd(headptr, 2);
	Print(headptr);
//	ReversePrint(headptr);
	headptr = Reverse(headptr);
	Print(headptr);

	getchar();
	return 0;
}
struct Node *getNewNode(int num)
{
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = num;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}
struct Node *InsertAtHead(struct Node *p, int num)
{
	struct Node *newNode = getNewNode(num);
	if (!p)
		p = newNode;
	else {
		p->prev = newNode;
		newNode->next = p;
		p = newNode;
	}
	return p;
}
struct Node *InsertAtEnd(struct Node *p, int num)
{
	struct Node *newNode = getNewNode(num);
	if (!p)
		p = newNode;
	else {
		struct Node *temp = p;
		while (temp->next)
			temp = temp->next;
		temp->next = newNode;
		newNode->prev = temp;
	}
	return p;
}
void Print(struct Node *p)
{
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
void ReversePrint(struct Node *p)
{
	while (p->next)
		p = p->next;
	while (p)
	{
		printf("%d ", p->data);
		p = p->prev;
	}
	printf("\n");
}
struct Node *Reverse(struct Node *headptr)
{
	struct Node *temp = headptr;
	while (temp->next)
		temp = temp->next;
	while (temp->prev)
	{
		struct Node *temp2 = temp->next;
		temp->next = temp->prev;
		temp->prev = temp2;
		temp = temp->prev;
	}

	return headptr;
}