#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
};
void Insert_list(struct Node **ptrToHead, int data, int position);
void Print_list(struct Node *head);
void Free_list(struct Node *head);

int main()
{
	struct Node *head = NULL;

	Insert_list(&head, 2, 1);		//List: 2
	Insert_list(&head, 3, 2);		//List: 2 3
	Insert_list(&head, 4, 1);		//List: 4 2 3
	Insert_list(&head, 5, 2);		//List: 4 5 2 3
	Print_list(head);
	Free_list(head);

	getchar();
	return 0;
}
void Insert_list(struct Node **ptrToHead, int data, int position)
{
	struct Node *temp1 = (struct Node *) malloc(sizeof(struct Node));
	temp1->data = data;
	temp1->next = NULL;
	if (position == 1)
	{
		temp1->next = *ptrToHead;
		*ptrToHead = temp1;
		return;
	}
	struct Node *temp2 = *ptrToHead;
	for (int i = 0; i < position - 2; i++)
	{
		temp2 = temp2->next;
	}
	temp1->next = temp2->next;
	temp2->next = temp1;
}
void Print_list(struct Node *head)
{
	while (head != NULL)
	{
		printf("%d ", head->data);
		head = head->next;
	}
}
void Free_list(struct Node *head)
{
	struct Node *temp = head;
	if (temp->next != NULL)
	{
		temp = temp->next;
		Free_list(temp);
	}
	free(head);
}