#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

void Text();
void CheckBlock(int * pBlock, FILE * read);
void CheckIdentifiers(int * pIdent, FILE * read);
void FileToFile();
void FileToScreen();
void KeyboardToFile();
void KeyboardToScreen();


int main()
{
	int izbor;
	while (1) {
		system("cls");
		Text();
		printf(">>");
		scanf_s("%d", &izbor);
		fflush(stdin);

		if (izbor == 1) {
			system("cls");
			FileToFile();
		}
		else if (izbor == 2) {
			system("cls");
			FileToScreen();
		}
		else if (izbor == 3) {
			system("cls");
			KeyboardToFile();
		}
		else if (izbor == 4) {
			system("cls");
			KeyboardToScreen();
		}
		else if (izbor == 0) {
			return 0;
		}
		system("cls");
	}
	return 0;
}

void Text() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("  Меню\n");
	printf("1. Четене програмата от файл и запис на резултата във файл\n");
	printf("2. Четене програмата от файл и извеждане на резултатата на екрана\n");
	printf("3. Четене на програмата от клавиатура и извеждане на резултата във файл\n");
	printf("4. Четене на програмата от калвиатурата и извеждане на екрана\n");
	printf("0.    Изход\n");
}

void CheckBlock(int * pBlock, FILE * read) {
	char ch[200];
	int allowPar = 1, allowCom = 1;
	unsigned int i;
	int checkA = 0, checkZ = 0;
	int checkEqual = 0;
	//text
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char blocks[] = "Програмата преброи блоковете на въведената от вас програма успешно!";
	char greshka[] = "Грешка!!!", greshka1[] = "Има незатворен блок в програмата!!!";

	while (fgets(ch, sizeof(ch), read)) {
		for (i = 0; i < strlen(ch); i++) {
			//proverka dali e v NIZ
			if ((ch[i] == '"') && (ch[i - 1] != '\\')) {
				if (allowPar == 1)
					allowPar--;
				else
					allowPar++;
			}
			//proverka dali e v komentar
			if ((ch[i] == '/') && (ch[i + 1] == '/'))
				break;
			if ((ch[i] == '/') && (ch[i + 1] == '*')) {
				allowCom--;
			}
			if ((ch[i] == '*') && (ch[i + 1] == '/')) {
				allowCom++;
			}
			//proverka za lyava ili dyasna skoba s cel opredelyane na bloka
			if ((ch[i] == '{') && allowPar && allowCom) {
				checkA++;
			}
			if ((ch[i] == '}') && allowPar && allowCom) {
				checkZ++;
			}
		}

	}
	//proverka dali blokat e zatvoren
	checkEqual = checkA - checkZ;
	if (checkEqual == 0) {
		printf("\n%s\n\n\n", blocks);
		*pBlock = checkA;
	}
	else {
		printf("\n%s !!!\n%s\n\n\n", greshka, greshka1);
		if (checkA > checkZ)
			*pBlock = checkZ;
		else
			*pBlock = checkA;
	}
}

void CheckIdentifiers(int * pIdent, FILE * read) {
	char ch[100];
	unsigned i;
	int allowPar = 1, allowCom = 1;
	int check;

	while (fgets(ch, sizeof(ch), read)) {
		check = 0;
		for (i = 0; i < strlen(ch); i++) {
			//proverka dali e v NIZ vkliuchitelno \" variant
			if ((ch[i] == '"') && (ch[i - 1] != '\\')) {
				if (allowPar == 1)
					allowPar--;
				else
					allowPar++;
			}
			//proverka dali e v KOMENTAR
			if ((ch[i] == '/') && (ch[i + 1] == '/')) {
				break;
			}
			if ((ch[i] == '/') && (ch[i + 1] == '*')) {
				allowCom--;
			}
			if ((ch[i] == '*') && (ch[i + 1] == '/')) {
				allowCom++;
			}
			//proverka dali e duma i dali e identifikator
			if (allowPar && allowCom) {
				if ((check == 0) && (((ch[i] >= 'A') && (ch[i] <= 'Z')) || ((ch[i] >= 'a') && (ch[i] <= 'z')) || (ch[i] == '_'))) {
					check = 1;
				}
			}
			//proverka dokade i identifikatora
			if (check) {
				while (1) {
					if (((ch[i] >= 'A') && (ch[i] <= 'Z')) || ((ch[i] >= 'a') && (ch[i] <= 'z')) || (ch[i] == '_') || ((ch[i] >= '0') && (ch[i] <= '9'))) {
						i++;
					}
					else {
						*pIdent = *pIdent + 1;
						check = 0;
						break;
					}
				}

			}
		}

	}
}

void FileToFile() {
	char wFileName[20], rFileName[20];
	int countBlock = 0;
	int ident = 0;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("Въведете името на файла, от който ще се чете програмата\n");
	scanf_s("%s", rFileName, sizeof(rFileName));
	FILE * read;

	fopen_s(&read, rFileName, "r");
	CheckBlock(&countBlock, read);
	fclose(read);

	fopen_s(&read, rFileName, "r");
	CheckIdentifiers(&ident, read);
	fclose(read);

	printf("Въведете името на файла, в който ще бъдат записани резултатите\n");
	scanf_s("%s", wFileName, sizeof(wFileName));

	FILE * write;
	fopen_s(&write, wFileName, "w");
	fprintf(write, "Блокове: %d \n", countBlock);
	fprintf(write, "Идентификатори: %d \n", ident);

	fclose(write);

	printf("\n__________________________________________________________\n");
	printf("Програмата е прочетена и във файал са записани резултатите\nса записани резултатите\n\n");
	system("pause");
}

void FileToScreen() {
	char rFileName[20];
	int countBlock = 0;
	int ident = 0;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("Въведете името на файла, от който ще четете\n");
	scanf_s("%s", rFileName, sizeof(rFileName));
	FILE * read;

	fopen_s(&read, rFileName, "r");
	CheckBlock(&countBlock, read);
	fclose(read);

	fopen_s(&read, rFileName, "r");
	CheckIdentifiers(&ident, read);
	fclose(read);

	printf("\nБлокове: %d \n\n", countBlock);
	printf("дентификатори: %d \n\n", ident);

	system("pause");
}

void KeyboardToFile() {
	char ch[200];
	char wFileName[20];
	int countBlock = 0;
	int ident = 0;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	FILE * storage;
	fopen_s(&storage, "storage.txt", "w");

	printf("Докато не въведете ''end'' програмата ще се записва->\n\n");
	while (1) {
		gets_s(ch, sizeof(ch));
		if ((ch[0] == 'e') && (ch[1] == 'n') && (ch[2] == 'd'))
			break;
		fprintf(storage, "%s\n", ch);
	}
	fclose(storage);

	FILE * read;

	fopen_s(&read, "storage.txt", "r");
	CheckBlock(&countBlock, read);
	fclose(read);

	fopen_s(&read, "storage.txt", "r");
	CheckIdentifiers(&ident, read);
	fclose(read);

	system("cls");
	printf("Въведете името на файла, в който ще бъдат въведени резултатите... \n");
	scanf_s("%s", wFileName, sizeof(wFileName));

	FILE * write;
	fopen_s(&write, wFileName, "w");
	fprintf(write, "Блокове: %d \n", countBlock);
	fprintf(write, "Идентификатори: %d \n", ident);
	fclose(write);

	printf("Готово\n");
	system("pause");
}

void KeyboardToScreen()
{
	char ch[200];
	int countBlock = 0;
	int ident = 0;
	FILE * read;
	FILE * storage;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	fopen_s(&storage, "storage.txt", "w");

	printf("Докато не въведете ''end'' програмата ще се записва->\n\n");
	while (1) {
		gets_s(ch, sizeof(ch));
		if ((ch[0] == 'e') && (ch[1] == 'n') && (ch[2] == 'd'))
			break;
		fprintf(storage, "%s\n", ch);
	}
	fclose(storage);



	fopen_s(&read, "storage.txt", "r");
	CheckBlock(&countBlock, read);
	fclose(read);

	fopen_s(&read, "storage.txt", "r");
	CheckIdentifiers(&ident, read);
	fclose(read);

	system("cls");
	printf("\nБлокове: %d \n\n", countBlock);
	printf("Идентификатори: %d \n\n", ident);

	system("pause");
}