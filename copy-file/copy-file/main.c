#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <Windows.h>

void copy(const char *srcPath, const char *destPath);

int main()
{
	SetConsoleOutputCP(1251);
	char sourceFileName[256], destFileName[256];
	int flag = 1;

	while (flag == 1)
	{
		flag = 0;
		printf("�������� ����� �� ����������, ����� ������ �� ���������: ");
		fgets(sourceFileName, 256, stdin);
		sourceFileName[strlen(sourceFileName) - 1] = '\0';
		for (int i = 0; i < strlen(sourceFileName); i++)
		{
			if (sourceFileName[i] == '.')
				if (sourceFileName[++i] != 'c')
				{
					printf("������ �� � � .� ������!");
					flag = 1;
				}
		}
	}
	printf("\n�������� ����� �� �����, ������ ������ �� �������� ����������: ");
	fgets(destFileName, 256, stdin);
	destFileName[strlen(destFileName) - 1] = '\0';
	
	copy(sourceFileName, destFileName);

	return 0;
}

void copy(const char *srcPath,const char *destPath)
{
	char buffer[256], ch;

	FILE *srcFile = fopen(srcPath, "r");

	FILE *destFile = fopen(destPath, "w");

	if (srcFile, destFile)
	{
		do
		{
			ch = fgets(buffer, 256, srcFile);

			fputs(buffer, destFile);
			fputs("\n", destFile);

		} while (ch != NULL);
	}
}