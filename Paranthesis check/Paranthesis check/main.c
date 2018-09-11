#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
	char bracket;
	struct Node *link;
};
int paranthesisCheck(char *, struct Node *);
struct Node *Push(struct Node *p, char symbol);
struct Node *Pop(struct Node *p);
char Top(struct Node *p);

int main()
{
	int check;
	char string[256];
	struct Node *head = NULL;

	while (fgets(string, 255, stdin))
	{
		if (!(check = paranthesisCheck(string, head)))
			printf("\nNo errors with parenthesis detected.\n\n");
	}
	return 0;
}
int paranthesisCheck(char *str, struct Node *p)
{
	char ch;
	size_t i;

	for (i = 0; i < strlen(str); i++)
	{
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
		{
			p = Push(p, str[i]);
		}
		if (str[i] == ')' || str[i] == ']' || str[i] == '}')
		{
			if (p == NULL)
			{
				printf("\nMissing opening parenthesis for \"%c\"\n\n", str[i]);
				return 1;
			}
			ch = Top(p);
			if ((str[i] == ')' && ch != '(') || (str[i] == ']' && ch != '[')
				|| (str[i] == '}' && ch != '{'))
			{
				printf("\nMissing closing parenthesis for \"%c\"\n\n", ch);
				return 2;
			}
			else
				p = Pop(p);
		}
	}
	if (p == NULL)
		return 0;
	printf("\nThere is unclosed parenthesis!\n\n");
	return 3;
}
struct Node *Push(struct Node *p, char symbol)
{
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
	temp->bracket = symbol;
	temp->link = p;

	return temp;
}
char Top(struct Node *p)
{
	return p->bracket;
}
struct Node *Pop(struct Node *p)
{
	struct Node *temp = p;
	p = p->link;
	free(temp);
	return p;
}