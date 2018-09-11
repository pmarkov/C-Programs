#include <stdio.h>
#include <string.h>

/*!!! ЗА ВЪВЕЖДАНЕ НА АРГУМЕНТИ: Project > Project Properties >
> Configuration Properties > Debugging > Command Arguments !!!*/

/*int main(int argc, char *argv[])
{

	while (--argc > 0)
		printf("%s%s", *++argv, (argc > 1) ? " " : "");

	getchar();
	return 0;
} */

/*Търсене на шаблон от командните аргументи*/

int getline(char *buffer, int maxsize);

int main(int argc, char *argv[])
{
	char line[256];

	while (getline(&line, 255) != NULL)
	{
		if (strstr(line, argv[1]) != NULL)
		{
			printf("\n%s\n", line);
		}
	}
	return 0;
}
int getline(char *buffer, int maxsize)
{
	int n = 0;
	char ch;

	while ((ch = getchar()) != EOF && ch != '\n' && n <= maxsize)
	{
		buffer[n] = ch;
		n++;
	}
	buffer[n] = '\0';
	return n;
}