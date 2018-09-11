#include <stdio.h>

int main()
{
	int arr[100];
	int n, min;
	printf("How many numbers? ");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		printf("\nEnter number %d: ", i + 1);
		scanf_s("%d", &arr[i]);
	}

	return 0;
}