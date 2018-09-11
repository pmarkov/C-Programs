#include <stdio.h>

void qsort(int *arr, int left, int right);
void swap(int *a, int *b);

int main()
{
	int arr[] = { 20, 10, 50, 30, 40, 80, 60, 70, 5, 123, 3, 51, 18, 4, -5 };
	
	qsort(arr, 0, 14);

	for (int i = 0; i < 15; i++)
		printf("%d ", arr[i]);

	getchar();
	return 0;
}

void qsort(int *arr, int left, int right)
{
	if (left >= right)
		return;
	int pivot = arr[left];
	int pIndex = left + 1;
	int last = left;

	for (int i = left + 1; i <= right; i++)
	{
		if (arr[i] < pivot)
		{
			swap(&arr[i], &arr[pIndex++]);
			last++;
		}
	}
	swap(&arr[left], &arr[last]);
	qsort(arr, left, pIndex - 1);
	qsort(arr, pIndex, right);
}
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}