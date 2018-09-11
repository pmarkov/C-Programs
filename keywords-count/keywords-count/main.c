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
	{ "char", 0 },
	{"const", 0},
	{"continue", 0},
	{"default", 0}
};

#define NKEYS (sizeof keytab / sizeof (keytab[0]))

void searchKeyWord(char *line, struct key *tab);

int main()
{
	int n;
	char line[256];

	FILE *fR = fopen("D:\\test.txt", "r");

	if (!fR) 
	{
		printf("Error opening file");
		return 1;
	}
	while (fgets(line, 255, fR) != NULL)
	{
		searchKeyWord(line, keytab);
	}
	for (n = 0; n < NKEYS; n++)
	{
		if (keytab[n].count > 0)
			printf("%4d  %s\n", keytab[n].count, keytab[n].word);
	}

	getchar();
	return 0;
}
void searchKeyWord(char *line, struct key *tab)
{
	char word[100];
	int i, j;

	for (i = 0; line[i] != '\0'; i++)
	{
		if (isalnum(line[i]))
		{
			j = 0;
			while (isalnum(line[i]) && line[i+1] != '\0')
			{
				word[j++] = line[i++];
			}
			word[j] = '\0';

			for (int k = 0; k < NKEYS; k++)
			{
				if (!strcmp(tab[k].word, word))
				{
					tab[k].count++;
					break;
				}
			}
		}
	}
}