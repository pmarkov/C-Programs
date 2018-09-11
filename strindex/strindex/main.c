#include <stdio.h>

int getline(char line[], int maxsize);  //записва реда в даден масив с големина maxsize
int strindex(char line[], char pattern[]);
/*strindex - търси даден шаблон в стринга и ако го намери връща като резултат 
индекса на стринга, откъдето почва шаблона, ако не връща 1*/

int main()
{
	char *patt = "ould";
	char line[256];

	while (getline(line, 256) > 0)
	{
		if (strindex(line, patt) > 0)
			printf("\t\t\t\t%s\n", line);
	}

	getchar();
	return 0;
}
int getline(char line[], int maxsize)
{
	int i = 0;
	char c;

	while ((c = getchar()) != EOF && i < maxsize && c != '\n')
	{
		line[i] = c;
		i++;
	}
	line[i] = '\0';
	return i;
}
int strindex(char line[], char pattern[])

{
	int i, j, k = 0;
	int flag = 0;

	for (i = 0; line[i] != '\0'; i++)
	{
		if (line[i] == pattern[k])
		{
			j = i;
			while (line[j] == pattern[k] && pattern[k] != '\0')
			{
				j++;
				k++;
			}
			if (pattern[k] == '\0')
				return i;
			else
				k = 0;
		}
	}
	return -1;
}