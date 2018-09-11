#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Header.h"

void inPut(int *arr, int n)
{
	int k;
	printf("\n");
	for (int i=0; i<n; i++)
		do
		{
			printf("Enter a number for arr[%d]: ", i);
			k = scanf("%d", &arr[i]);
		} while (k != 1);
}
void outPut(int *arr, int n)
{
	for (int i = 0; i < n; i++)
		printf("\narr[%d]= %d", i, arr[i]);
}
int MaxMin(int *arr, int n, int *max, int *min, int *indMax)
{
	int indMin;
	*max = *min = arr[0];
	indMin = *indMax;
	for (int i = 1; i < n; i++) {
		if (*max < arr[i]) {
			*max = arr[i];
			*indMax = i;
		}
		if (*min > arr[i]) {
			*min = arr[i];
			indMin = i;
		}
	}
	return indMin;
}
int swap(int *arr, int *max, int *min, int *indMax, int *indMin)
{
	int tmp;
	tmp = arr[*indMax];
	arr[*indMax] = arr[*indMin];
	arr[*indMin] = tmp;

	tmp = *indMax;
	*indMax = *indMin;
	*indMin = tmp;
}
int main()
{
	int arr[256], max, min, indMax, indMin, n, tmp;

	printf("How many numbers you want to enter: ");
	scanf("%d", &n);
	inPut(arr, n);
	outPut(arr, n);
	
	indMin = MaxMin(arr, n, &max, &min, &indMax);
	printf("\n\nIndMin: %d", indMin);
	printf("\nIndMax: %d", indMax);


	return 0;
}