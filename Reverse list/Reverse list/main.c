#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
};

struct Node *Insert(struct Node *head, int num);
struct Node *Reverse(struct Node *head);
void Print(struct Node *p);
void ReversePrint(struct Node *p);
void Free(struct Node *p);

int main()
{
	struct Node *head = NULL;

	head = Insert(head, 5);
	head = Insert(head, 6);
	head = Insert(head, 7);
	head = Insert(head, 8);
	Print(head);
	head = Reverse(head);
	Print(head);
	ReversePrint(head);
	Free(head);

	system("pause");
	return 0;
}
struct Node *Insert(struct Node *head, int num)
{
	struct Node *temp = (struct Node *) malloc(sizeof(struct Node));
	if (!temp)
		return NULL;
	temp->data = num;
	temp->next = NULL;
	if (!head)
		head = temp;
	else
	{
		struct Node *temp1 = head;
		while (temp1->next)
			temp1 = temp1->next;
		temp1->next = temp;		
	}
	return head;
}
void Print(struct Node *p)
{
	if (!p)
	{
		printf("\n");
		return;
	}
	printf("%d ", p->data);
	Print(p->next);
}
void ReversePrint(struct Node *p)
{
	if (!p)
		return;
	ReversePrint(p->next);
	printf("%d ", p->data);
}
struct Node *Reverse(struct Node *head)
{
	struct Node *prev, *current, *next;
	current = head;
	prev = NULL;

	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
	return head;
}
void Free(struct Node *p)
{
	if (p)
	{
		Free(p->next);
		free(p);
	}	
}