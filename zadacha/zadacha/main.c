#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void replace(FILE *);

int main()
{
	FILE *read;
	char fname[256];

	printf("Enter a file for reading: ");
	fgets(fname, 255, stdin);
	fname[strlen(fname) - 1] = '\0';
	if (fopen_s(&read, fname, "r") != 0)
	{
		printf("The file doesn't exist!\n");
		system("pause");
		return 1;
	}

	replace(read);

	return 0;
}
void replace(FILE *fpR)
{
	FILE *fwrite;
	char fname[256];
	char buffer[256];


	printf("Enter a file for writing: ");
	fgets(fname, 256, stdin);
	fname[strlen(fname) - 1] = '\0';

	if (fopen_s(&fwrite, fname, "w") != 0)
	{
		printf("This file doesn't exist!");
		return;
	}
	while (1)
	{
		size_t readBytes = fread(buffer, 1, 255, fpR);
		if (readBytes == 0)
			break;
		buffer[readBytes] = '\0';
		printf("%s", buffer);
		printf("\n");
		system("pause");
	}
}