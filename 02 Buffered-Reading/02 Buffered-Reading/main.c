#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *file = fopen("main.c", "r");
	if (!file)
	{
		fprintf(stderr, "Error opening file!");
		return 1;
	}
	char buffer[129];

	while(1)
	{
		size_t readBytes = fread(buffer, 1, 128, file);
		if (readBytes == 0)
			break;
		buffer[readBytes] = '\0';
		printf("%lu", readBytes);
		printf("\n%s", buffer);
	}

	getchar();
	return 0;
}