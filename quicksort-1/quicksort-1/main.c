#include <stdio.h>

void qsort(int *arr, int left, int right);
void swap(int *a, int *b);

int main()
{
	int arr[] = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3 };

	qsort(arr, 0, 9);

	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);

	getchar();
	return 0;
}
void qsort(int *arr, int left, int right)
{
	if (left >= right)
		return;

	int pIndex = partition(arr, left, right);
	qsort(arr, left, pIndex - 1);
	qsort(arr, pIndex + 1, right);
}
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int partition(int *arr, int left, int right)
{
	int pivot = arr[right];
	int pIndex = left;

	for (int i = left; i < right; i++)
		if (arr[i] < pivot)
		{
			swap(&arr[i], &arr[pIndex]);
			pIndex++;
		}
	swap(&arr[pIndex], &arr[right]);

	return pIndex;
}