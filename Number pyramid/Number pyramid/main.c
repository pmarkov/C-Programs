#include <stdio.h>

void printPyramid(int num, int i)
{
	if (i > num)
		return;
	for (int j = 1; j <= i; j++)
		printf("%d ", i);
	printf("\n");
	printPyramid(num, ++i);
}

void printReverse(int num, int i)
{
	if (i < 1)
		return;
	for (int j = 1; j <= i; j++)
		printf("%d ", i);
	printf("\n");
	printReverse(num, --i);
}

int main()
{
	int a;

	printf("Enter a number: ");
	scanf_s("%d", &a);

	printPyramid(a, 1);
	printReverse(a, a-1);

	system("pause");
	return 0;
}