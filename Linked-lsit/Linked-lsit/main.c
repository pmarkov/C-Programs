#include <stdio.h>
#include <stdlib.h>

/*Въвежда числа в началото на листа.*/

struct Node {
	int data;
	struct Node *next;
};

void insert_list(int x, struct Node** ptrToHead);
void print_list(struct Node *head);
void free_list(struct Node *head);

int main()
{
	struct Node *head = NULL;		//листът е празен

	int n, x;		

	printf("How many numbers? ");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("\nEnter a number:");
		scanf_s("%d", &x);
		insert_list(x, &head);
		print_list(head);
	}
	free_list(head);

	system("pause");
	return 0;
}
void insert_list(int x, struct Node** ptrToHead)
{
	struct Node *temp = (struct Node *) malloc(sizeof(struct Node));
	temp->data = x;
	temp->next = *ptrToHead;
	*ptrToHead = temp;
}
void print_list(struct Node *head)
{
	printf("List is: ");
	while (head != NULL)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}
void free_list(struct Node *head)
{
	struct Node *temp = head;
	if (temp->next != NULL)
	{
		temp = temp->next;
		free_list(temp);
	}
	free(head);
}