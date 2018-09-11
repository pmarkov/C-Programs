#include <stdio.h>
#include <conio.h>
#include <Windows.h>
int main()
{
	SetConsoleOutputCP(1251);
	int digit, punc, letters;
	char ch;
	digit = 0;
	punc = 0;
	letters = 0;
	printf("Въведете символи, ENTER за стоп: \n");
	
	do{
		ch = _getche();
		switch (ch) {
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		case '0':
			digit++;
			break;
		case '.':
		case ',':
		case '-':
		case '!':
		case '?':
		case '"':
		case ':':
		case ';':
			punc++;
			break;
		default:
			letters++;
			break;
		}
	} while (ch != '\r');
	printf("\nDigits: %d", digit);
	printf("\nPunctuals: %d", punc);
	printf("\nLetters: %d", letters);
	return 0;
}