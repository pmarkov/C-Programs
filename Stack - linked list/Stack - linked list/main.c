#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *link;
};
struct Node *Insert(struct Node *, int num);
void Push(struct Node **top, int num);
struct Node *Pop(struct Node *top);
void Print(struct Node *ptr);


int main()
{
	struct Node *top = NULL;
	top = Insert(top, 5);
	top = Insert(top, 6);
	top = Insert(top, 7);
	top = Insert(top, 8);
	Push(&top, 4);
	Print(top);
	top = Pop(top);
	Print(top);

	getchar();
	return 0;
}

struct Node *Insert(struct Node *ptr, int num)
{
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->data = num;
	newNode->link = NULL;

	if (ptr == NULL)
		ptr = newNode;
	else {
		struct Node *temp = ptr;
		while (temp->link)
			temp = temp->link;
		temp->link = newNode;
	}
	return ptr;
}
void Push(struct Node **top, int num)
{
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->data = num;
	newNode->link = *top;
	*top = newNode;
}
struct Node *Pop(struct Node *top)
{
	if (top == NULL)
		return NULL;
	struct Node *temp;
	temp = top;
	top = top->link;
	free(temp);
	return top;
}
void Print(struct Node *ptr)
{
	while (ptr) {
		printf("%d ", ptr->data);
		ptr = ptr->link;
	}
	printf("\n");
}