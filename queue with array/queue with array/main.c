#include <stdio.h>

void Enqueue(int *arr, int num, int *front, int *rear, int N);
void Dequeue(int *arr, int *front, int *rear, int N);
void Print(int *arr, int front, int rear, int N);
int Front(int *arr, int front);
int isEmpty(int *arr, int front);

int main()
{
	int A[10];
	int N = 10;
	int front, rear;
	front = rear = -1;

	Enqueue(A, 1, &front, &rear, N);
	Enqueue(A, 2, &front, &rear, N);
	Enqueue(A, 3, &front, &rear, N);
	Enqueue(A, 4, &front, &rear, N);
	Enqueue(A, 5, &front, &rear, N);
	Enqueue(A, 6, &front, &rear, N);
	Enqueue(A, 7, &front, &rear, N);
	Enqueue(A, 8, &front, &rear, N);
	Enqueue(A, 9, &front, &rear, N);
	Enqueue(A, 10, &front, &rear, N);
	Print(A, front, rear, N);
	Enqueue(A, 11, &front, &rear, N);
	Dequeue(A, &front, &rear, N);
	Print(A, front, rear, N);
	Enqueue(A, 11, &front, &rear, N);
	Print(A, front, rear, N);

	getchar();
	return 0;
}
void Enqueue(int *arr, int num, int *front, int *rear, int N)
{
	if ((*rear + 1) % N == *front)
		return;
	else if (isEmpty(arr, *front))
		*front = *rear = 0;
	else {
		*rear = (*rear + 1) % N;
	}
	arr[*rear] = num;
}
void Dequeue(int *arr, int *front, int *rear, int N)
{
	if (isEmpty(arr, *front))
		return;
	else if (*front == *rear)
		*front = *rear = -1;
	else
		*front = (*front + 1) % N;
}
int isEmpty(int *arr, int front)
{
	if (front == -1)
		return 1;
	return 0;
}
void Print(int *arr, int front, int rear, int N)
{
	for (; (front + 1) % 10 != (rear + 1) % 10; front++)
		printf("%d ", arr[front]);
	printf("%d ", arr[rear]);
	printf("\n");
}
int Front(int *arr, int front)
{
	if (front == -1)
	{
		printf("The queue is empty!");
		return 0;
	}
	return arr[front];
}