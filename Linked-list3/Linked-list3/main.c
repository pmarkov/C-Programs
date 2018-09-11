#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
};
struct Node *head;

void insert_list(int data);
void print_list();
void delete_element(int n);		//delete element at n-th position
void free_list(struct Node *head);

int main()
{
	head = NULL;
	insert_list(2);
	insert_list(4);
	insert_list(6);
	insert_list(5);

	print_list();

	int n;
	printf("\nEnter a position: ");
	scanf_s("%d", &n);
	delete_element(n);
	print_list();
	free_list(head);

	system("pause");
	return 0;
}
void insert_list(int data)
{
	struct Node *temp = (struct Node*) malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = NULL;
	if (!head)
	{
		head = temp;
		return;
	}

	struct Node *temp1 = head;
	while (temp1->next != NULL)
		temp1 = temp1->next;
	temp1->next = temp;
}
void print_list()
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
void delete_element(int n)
{
	struct Node *temp1 = head;

	if (n == 1)
	{
		head = temp1->next;
		free(temp1);
		return;
	}

	for (int i = 0; i < n - 2; i++)
		temp1 = temp1->next;
	//temp1 сочи към (n-1)-вия възел
	struct Node *temp2 = temp1->next; //n-тия възел
	temp1->next = temp2->next;		  //(n+1)-вия възел
	free(temp2);
}
void free_list(struct Node *head)
{
	if (head->next)
	{
		free_list(head->next);
	}
	free(head);
}