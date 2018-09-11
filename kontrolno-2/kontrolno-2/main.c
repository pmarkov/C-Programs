#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int f1(FILE *f);
int f2(FILE *f, char c);

int main()
{
	FILE *f;
	char fname[50];
	char c;
	int sum, number;

	printf("Enter the file name: ");
	if (fgets(fname, 50, stdin) == NULL)
	{
		printf("Error reading file name!");
		return 1;
	}
	fname[strlen(fname) - 1] = '\0';
	if ((f = fopen(fname, "rt")) == NULL)
	{
		printf("This file doesn't exists!");
		return 1;
	}
	do {
		printf("\nEnter a number: ");
		c = getchar();
		while (getchar() != '\n');
	} while (c < '0' || c > '9');

	sum = f1(f);
	rewind(f);
	number = f2(f, c);

	printf("\nThe sum of the positive numbers is: %d", sum);
	printf("\nThe number %c is counted %d times.", c, number);
	fclose(f);

	system("pause");

	return 0;
}
int f1(FILE *f)
{
	int sum = 0;
	int next;

	while (fscanf_s(f, "%d", &next) != EOF)
	{
		if (next > 0)
			sum += next;
	}
	return sum;
}
int f2(FILE *f, char c)
{
	char next;
	int count = 0;

	while ((next = fgetc(f)) != EOF)
	{
		if (next == c)
			count++;
	}
	return count;
}