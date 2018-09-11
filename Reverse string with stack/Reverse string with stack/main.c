#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Push(char *stack, char symbol, int *top);
char Pop(char *stack, int *top);
void ReverseString(char *str, int len);			//Reverse with Push and Pop
void Reverse(char *str);

int main()
{
	char str[] = { "Hello" };


	ReverseString(str, strlen(str));

	printf("%s\n", str);
	Reverse(str);
	printf("%s\n", str);

	getchar();
	return 0;
}
void ReverseString(char *str, int len)
{
	char stack[101];
	int top = -1;
	int i;
	for (i = 0; i < len; i++)
	{
		Push(stack, str[i], &top);
	}
	stack[len] = '\0';

	for (i = 0; i < len; i++)
	{
		str[i] = Pop(stack, &top);
	}
}
void Push(char *stack, char symbol, int *top)
{
	stack[++(*top)] = symbol;
}
char Pop(char *stack, int *top)
{
	if (*top == -1)
	{
		printf("Stack is empty\n");
		return 0;
	}
	char ch = stack[*top];
	(*top)--;
	return ch;
}
void Reverse(char *str)
{
	int i, j;
	for (i = 0, j = strlen(str) - 1; i < j; i++, j--)
	{
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}