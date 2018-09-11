#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main()
{
	char fileName[256], logFileName[256];
	int flag = 1;
	while (flag == 1)
	{
		flag = 0;
		printf("Enter the .c file you want to open: ");
		fgets(fileName, 256, stdin);
		//fileName[strlen(fileName) - 1] = '\0';

		for (int i = 0; i < strlen(fileName); i++) 
		{
			if (fileName[i] == '.')
				if (fileName[++i] != 'c')
				{
					flag = 1;
					printf("\nThis is not a .c file! Try again.\n");
				}
		}
	}
	printf("Enter the file where you want to copy the .c file: ");
	fgets(logFileName, 256, stdin);
	//logFileName[strlen(logFileName) - 1] = '\0';
	
	copy(fileName, logFileName);


	return 0;
}

void copy(char *srcPath, char *destPath)
{
	char openFile[256];

	FILE *file = fopen(srcPath, "r");
	FILE *logfile = fopen(destPath, "w");

	if (file)
	{
		while (!feof(file))
		{
			fgets(openFile, 256, file);
			openFile[strlen(openFile) - 1] = '\0';

			fputs(openFile, logfile);
			fputs("\n", logfile);
			fflush(logfile);
		}
	}
	else {
		printf("The file couldn't be open!");
	}
}