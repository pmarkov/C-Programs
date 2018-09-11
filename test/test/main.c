#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int strncmp(char *, char *, int);

int main()
{
	char *str1 = "Copy-test";
	char str2[10];
	char *str3 = "Hello";

	strncpy(str2, str1, 5);
	str2[5] = '\0';
	printf("%s\n", str2);

	strncpy(str2, str3, 3);
	printf("\n%s", str2);

	strncat(str2, str1, 3);
	printf("\n\n%s", str2);

	int val = strncmp(str1, str3, 3);

	printf("\n\n%d", val);

	int value = strncmp(str1, str3, 3);
	printf("%d", value);

	getchar();
	return 0;
}
int strncmp(char *str1, char *str2, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (*(str1 + i) != *(str2 + i))
			return -1;
	}
	return 0;
}
/*
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct key {
	char *word;
	int count;
} keytab[] =
{
	{ "auto" , 0 },
	{ "break", 0 },
	{ "case", 0 },
	{ "char", 0 }
};

int searchKeyWord(char *line, struct key *tab);

int main()
{
	char line[256];

	FILE *fR = fopen("D:\\test.txt", "rt");

	if (!fR)
	{
		printf("Error opening file");
		return 1;
	}
	fgets(line, 255, fR);

	searchKeyWord(line, keytab);


	getchar();
	return 0;
}
int searchKeyWord(char *line, struct key *tab)
{
	char word[100];
	int i, j;

	for (i = 0; line[i] != '\0'; i++)
	{
		if (isalpha(line[i]))
		{
			j = 0;
			while (isalpha(line[i]))
			{
				word[j++] = line[i++];
			}
			word[j] = '\0';
			printf("%s ", word);
		}
	}
} */

