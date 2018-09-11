#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
};

void Enqueue(struct Node **front, struct Node **tail, int num);
void Dequeue(struct Node **front, struct Node **tail);
void Print(struct Node *front);
int Front(struct Node *front);
int isEmpty(struct Node *front);

int main()
{
	struct Node *tail = NULL;
	struct Node *front = NULL;
	int top, check;

	Dequeue(&front, &tail);
	Enqueue(&front, &tail, 2);
	Enqueue(&front, &tail, 3);
	Enqueue(&front, &tail, 4);
	top = Front(front);
	check = isEmpty(front);
	Print(front);
	Dequeue(&front, &tail);
	Print(front);

	getchar();
	return 0;
}

void Enqueue(struct Node **front, struct Node **tail, int num)
{
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
	temp->data = num;
	temp->next = NULL;
	if (*front == NULL && *tail == NULL){
		*front = *tail = temp;
		return;
	}
	(*tail)->next = temp;
	*tail = temp;
}
void Dequeue(struct Node **front, struct Node **tail)
{
	if (isEmpty(*front)) {
		printf("The list is empty.\n");
		return;
	}
	struct Node *temp = *front;
	if (*front == *tail)
		*front = *tail = NULL;
	else
		*front = (*front)->next;
	free(temp);
}
void Print(struct Node *front)
{
	while (front)
	{
		printf("%d ", front->data);
		front = front->next;
	}
	printf("\n");
}
int Front(struct Node *front)
{
	if (front == NULL)
	{
		printf("The list is empty.");
		return 0;
	}
	return front->data;
}
int isEmpty(struct Node *front)
{
	if (front == NULL)
		return 1;
	return 0;
}