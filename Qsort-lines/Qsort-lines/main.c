#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);
void swap(char *lineptr[], int i, int j);

int main()
{
	char *lineptr[MAXLINES];
	int nlines;

	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		qsort(lineptr, 0, nlines - 1);
		writelines(lineptr, nlines);
		getchar();
		return 0;
	}
	else {
		printf("Error: too big input to sort!");
		return 1;
	}
}

int readlines(char *lineptr[], int maxlines)
{
	char *ptr;
	char line[256];
	int nlines = 0;

	while (fgets(line, 256, stdin) != NULL)
	{
		if (nlines >= MAXLINES)
			return -1;
		else
		{
			line[strlen(line) - 1] = '\0';
			ptr = (char *)malloc(strlen(line) + 1);
			strcpy(ptr, line);
			lineptr[nlines++] = ptr;
		}
	}
	return nlines;
}
void writelines(char *lineptr[], int nlines)
{
	for (int i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}
void qsort(char *lineptr[], int left, int right)
{
	if (left < right)
	{
		int i;
		int last = left;

		for (i = left + 1; i <= right; i++)
		{
			if (strcmp(lineptr[i], lineptr[left]) < 0)
				swap(lineptr, ++last, i);
		}
		swap(lineptr, last, left);

		qsort(lineptr, left, last - 1);
		qsort(lineptr, last + 1, right);
	}
	return;
}
void swap(char *lineptr[], int i, int j)
{
	char *temp = lineptr[i];
	lineptr[i] = lineptr[j];
	lineptr[j] = temp;
}