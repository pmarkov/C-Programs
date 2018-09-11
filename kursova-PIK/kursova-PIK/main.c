#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <ctype.h>
#include <errno.h>

void readFileName(char *fname, int flag);
int countIdentifiers(char *buffer, int *idCount);
void fileToFile(FILE *read, FILE *write);
void fileToScreen(FILE *read);
void keyboardToFile(FILE *write);
void keyboardToScreen();

int main()
{
	SetConsoleOutputCP(1251);
	int p = 0, k;
	int check = 0;
	char fname[256];
	FILE *read, *write;
	errno_t err;

	do
	{
		printf("1.Четене на програма от файл и записване на резултата във файл.");
		printf("\n2.Четене на програма от файл и записване на резултата на екрана.");
		printf("\n3.Четене на програма от клавиатурата и записване във файл.");
		printf("\n4.Четене на програма от клавиатурата и извеждане на екрана.");
		printf("\n5.Изход(5-9).");
		do
		{
			printf("\nИзберете опция: ");
			k = scanf_s("%d", &p);
			while (getchar() != '\n');

		} while (k != 1);
		switch (p)
		{
		case 1:
			check = 1;
			readFileName(fname, check);
			if ((err = fopen_s(&read, fname, "r")) != 0)
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
			check = 0;
			readFileName(fname, check);
			if ((err = fopen_s(&write, fname, "w")) != 0)
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
			fileToFile(read, write);
			break;
		case 2:
			check = 1;
			readFileName(fname, check);
			if ((err = fopen_s(&read, fname, "r")) != 0)
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
			fileToScreen(read);
			break;
		case 3:
			check = 0;
			readFileName(fname, check);
			if ((err = fopen_s(&write, fname, "w")) != 0)
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
			keyboardToFile(write);
			break;
		case 4:
			keyboardToScreen();
			break;
		case 5:
			exit(1);
			break;
		default:
			p = 0;
		}
	} while (p != 0);

	return 0;
}
void readFileName(char *fname, int flag)
{
	if (flag == 1)
	{
		do
		{
			printf("\nВъведете името на файла, който искате да четете(.с): ");
			fgets(fname, 256, stdin);
			fname[strlen(fname) - 1] = '\0';
		} while (fname[strlen(fname) - 2] != '.' || fname[strlen(fname) - 1] != 'c');
	}
	if (flag == 0)
	{
		printf("\nВъведете име на файла, където искате да запишете резултата: ");
		fgets(fname, 255, stdin);
		fname[strlen(fname) - 1] = '\0';
		printf("\n");
	}
}
void fileToFile(FILE *read, FILE *write)
{
	int idCount = 0;
	int lineCount = 0;
	char buffer[256];

	while (fgets(buffer, 256, read) != NULL)
	{
		lineCount += countIdentifiers(buffer, &idCount);
	}

	fprintf(write, "Броят на идентификаторите е: %d", idCount);
	fprintf(write, "\nБроят на редовете е: %d", lineCount + 1);
	fclose(write);
	fclose(read);
}
void fileToScreen(FILE *read)
{
	int idCount = 0;
	int lineCount = 0;
	char buffer[256];

	while (fgets(buffer, 256, read) != NULL)
	{
		lineCount += countIdentifiers(buffer, &idCount);
	}
	printf("\nБроят на идентификаторите е: %d", idCount);
	printf("\nБроят на редовете е: %d\n\n", lineCount + 1);
	fclose(read);
}
void keyboardToFile(FILE *write)
{
	int idCount = 0;
	int lineCount = 0;
	char buffer[256];

	printf("\nЗа край на въвеждането натиснете Ctrl/Z!\n");
	while (fgets(buffer, 256, stdin) != NULL)
	{
		lineCount += countIdentifiers(buffer, &idCount);
	}
	fprintf(write, "Броят на идентификаторите е: %d", idCount);
	fprintf(write, "\nБроят на редовете е: %d", lineCount + 1);
	fclose(write);
}
void keyboardToScreen()
{
	int idCount = 0;
	int lineCount = 0;
	char buffer[256];

	printf("\nЗа край на въвеждането натиснете Ctrl/Z!\n");
	while (fgets(buffer, 256, stdin) != NULL)
	{
		lineCount += countIdentifiers(buffer, &idCount);
	}
	printf("\nБроят на идентификаторите е: %d", idCount);
	printf("\nБроят на редовете е: %d\n\n", lineCount + 1);
}

int countIdentifiers(char *buffer, int *idCount)
{
	static int inComment = 0;
	int lineCount = 0;
	int i;

	for (i = 0; buffer[i] != '\0'; i++)
	{
		if (buffer[i] == '/' && buffer[i + 1] == '/')		//skipping '//' comments
		{
			while (buffer[i] != '\n')
				i++;
		}
		if (buffer[i] == '/' && buffer[i + 1] == '*')		//skipping /**/ comments
		{
			inComment = 1;
			i += 2;
			while (buffer[i] != '\n')
			{
				if (buffer[i] == '*' && buffer[i + 1] == '/')
				{
					inComment = 0;
					i += 2;
					break;
				}
				i++;
			}
		}
		if (inComment == 1)
		{
			while (buffer[i] != '\n')
			{
				if (buffer[i] == '*' && buffer[i + 1] == '/')
				{
					inComment = 0;
					i += 2;
					break;
				}
				i++;
			}
		}
		if (buffer[i] == '"')				//skipping brackets
		{
			while (buffer[i] != '\0')
			{
				if (buffer[i + 1] == '"')
				{
					if (buffer[i] == '\\')
					{
						i += 2;
						continue;
					}
					else
					{
						i += 2;
						break;
					}
				}
				i++;
			}
		}
		if (isalpha(buffer[i]) || buffer[i] == '_')			//counting identifiers
		{
			if (isalnum(buffer[i + 1]))
			{
				do
				{
					i++;
				} while (isalnum(buffer[i]));
			}
			(*idCount)++;
		}
	}
	for (i = 0; buffer[i] != '\0'; i++)				//counting lines
	{
		if (buffer[i] == '\n')
			lineCount++;
	}
	return lineCount;
}