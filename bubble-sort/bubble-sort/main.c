#include <stdio.h>

void asc_bubble_sort(int *numbers, int size);
void desc_bubble_sort(int *num, int size);
void array(int *num, int size);

int main()
{
	int k, j;
	int num[100];
	int size;
	char choice;
	
	do
	{
		printf("How many numbers do you want to sort(max 100)?:");
		k = scanf_s("%d", &size);
		if (size > 100)
		{
			printf("\nThe number is too big! Try again!\n");
			k = 0;
		}
		if (size <= 0)
		{
			printf("\nInvalid input!\n");
			k = 0;
		}
		while (getchar() != '\n');
	} while (k != 1);

	array(num, size);
	
	do
	{
		printf("\nHow do you want to sort the numbers('A' for ascending or 'D' for descending)?");
		choice = getchar();
		while (getchar() != '\n');
	} while (choice != 'A' && choice != 'a' && choice != 'D' && choice != 'd');
	if(choice == 'A' || choice == 'a')
		asc_bubble_sort(num, size);
	if (choice == 'D' || choice == 'd')
		desc_bubble_sort(num, size);

	printf("\n\n");
	
	for (j = 0; j < size; j++)
		printf("%d ", num[j]);

	getchar();
	return 0;
}
void asc_bubble_sort(int *numbers, int size)
{
	int isSwapped = 1;
	int i;

	while (isSwapped)
	{
		isSwapped = 0;
		for (i = 0; i < size-1; i++)
		{
			if (numbers[i] > numbers[i + 1])
			{
				int oldValue = numbers[i];
				numbers[i] = numbers[i + 1];
				numbers[i + 1] = oldValue;
				isSwapped = 1;
			}
		}
	}
}
void desc_bubble_sort(int *num, int size)
{
	int isSwapped = 1;
	int i;

	while (isSwapped)
	{
		isSwapped = 0;
		for (i = 0; i < size; i++)
		{
			if (num[i] < num[i + 1])
			{
				int oldValue = num[i];
				num[i] = num[i + 1];
				num[i + 1] = oldValue;
				isSwapped = 1;
			}
		}
	}
}
void array(int *num, int size)
{
	int k;

	for (int j = 0; j < size; j++)
	{
		do
		{
			printf("\nEnter number %d:", j + 1);
			k = scanf_s("%d", &num[j]);
			while (getchar() != '\n');
		} while (k != 1);
	}
//	return *num;
}