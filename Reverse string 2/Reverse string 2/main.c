#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *str, int lenght, int n, int m);

int main()
{
	char ch;
	char str[256];

	do
	{
		printf("Enter text: ");
		fgets(str, 255, stdin);
		str[strlen(str) - 1] = '\0';

		int lenght = strlen(str);

		reverse(str, lenght, 0, lenght - 1);
		printf("\nReversed: %s\n", str);
	} while ((ch = getchar()) != EOF);

	return 0;
}
void reverse(char *str, int lenght, int n, int m)
{
	if (n >= m)
	{
		str[lenght] = '\0';
		return;
	}
		
	char temp = str[n];
	str[n] = str[m];
	str[m] = temp;
	
	reverse(str, lenght, ++n, --m);
}