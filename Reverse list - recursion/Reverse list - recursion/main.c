#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

struct Node* Insert(struct Node* p, int num);
struct Node* Reverse(struct Node* p);
void Print(struct Node* p);
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
	Free(head);

	getchar();
	return 0;
}
struct Node* Insert(struct Node* p, int num)
{
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
	temp->data = num;
	temp->next = NULL;

	if (!p)
		p = temp;
	else
	{
		struct Node *temp1 = p;
		while (temp1->next)
			temp1 = temp1->next;
		temp1->next = temp;
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
struct Node* Reverse(struct Node* head)
{
	struct Node *p = head;
	if (p->next == NULL)
	{
		head = p;
		return head;
	}
	head = Reverse(p->next);
	p->next->next = p;
	p->next = NULL;
	return head;
}
void Free(struct Node *p)
{
	if (!p->next)
		return;
	Free(p->next);
	free(p);
}