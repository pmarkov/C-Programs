#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *str, char *result, int lenght, int n, int m);

int main()
{
	char str[256];

	while (1)
	{
		printf("Enter text: ");
		fgets(str, 256, stdin);
		str[strlen(str) - 1] = '\0';

		int lenght = strlen(str);
		char *result = malloc(lenght + 1);
		if (!result)
		{
			printf("Couldn allocate memory!");
			return 1;
		}

		reverse(str, result, lenght + 1, 0, lenght - 1);
		printf("\nReversed: %s\n", result);
		free(result);
		if (getchar() == EOF)
			break;
	}

	return 0;
}
void reverse(char *str, char *result, int lenght, int n, int m)
{
	if (n == lenght - 1)
	{
		result[n] = '\0';
		return;
	}
	char ch = str[n];
	result[m] = ch;

	reverse(str, result, lenght, ++n, --m);
}