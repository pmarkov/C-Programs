#include <stdio.h>
#include <string.h>

void spaceCheck(char *string);
void readLine(char *string);

int main()
{
	char line[256];

	do
	{
		readLine(line);
		spaceCheck(line);
		printf("%s", line);
	} while (printf("For exit - Ctrl/Z:"), getchar() != EOF);

	getchar();
	return 0;
}
void spaceCheck(char *string)
{
	int i;
	for (i = 0; string[i] != '\0'; i++)
	{
		if (string[0] == ' ')
		{
			do
			{
				string[i] = string[i + 1];
				i++;
			} while (string[i] != '\n');
		}
	}
}
void readLine(char *string)
{
	printf("Enter a string:");
	fgets(string, 256, stdin);
//	string[strlen(string) - 1] = '\0';
}