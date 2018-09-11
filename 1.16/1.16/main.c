#include <stdio.h>
#include <string.h>

int getline(char line[], int maxline);
void copy(char *to, char *from);

int main()
{
	int len;
	int max = 0;
	char line[256];
	char longest[256];
	char text[1000];

	while ((len = getline(line, 256)) > 0)
	{
		if (len > max)
		{
			max = len;
			copy(longest, line);
		}
	}

	if (max > 0)
		printf("%s", longest);
	
	system("\npause");
	return 0;
}
int getline(char s[], int lim)
{
	int i, c;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
	if (c == '\n')
	{
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
void copy(char *to, char *from)
{
	int i;

	i = 0;

	while ((to[i] = from[i]) != '\0')
		i++;
}