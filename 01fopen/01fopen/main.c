#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *file = fopen("main.c", "r");
	
	if (file)
	{
		while (1)
		{
			char ch = fgetc(file);
			if (ch == EOF)
				break;
			printf("%c", ch);
		}

		fclose(file);
	}

	getchar();
	return 0;
}