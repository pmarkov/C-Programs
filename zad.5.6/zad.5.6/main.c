#include <stdio.h>

int getline(char *buffer, int maxsize);
int strindex(char *buffer, char *pattern);

int main()
{

	char *pattern = "shit";
	char line[256];

	getline(line, 255);
	printf("\n%s", line);

	int val = strindex(line, pattern);
	printf("\n\n%d", val);

	getchar();
	return 0;
}
int getline(char *buffer, int maxsize)
{
	int i = 0;
	char ch;

	while ((ch = getchar()) != EOF && ch != '\n' && i < maxsize)
	{
		*(buffer + i) = ch;
		i++;
	}
	*(buffer + i) = '\0';

	return i;
}
int strindex(char *buffer, char *pattern)
{
	int i, j;
	int k;
	for (i = 0, j = 0; *(buffer + i) != '\0'; i++)
	{
		j = 0;
		if (*(buffer + i) == *pattern)
		{
			k = i;
			while (*(buffer + k) == *(pattern + j) && pattern != '\0')
			{
				k++;
				j++;
			}
			if (*(pattern + j) == '\0')
				return i;
		}
	}
	return -1;
}