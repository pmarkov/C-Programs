#include <stdio.h>
#include <conio.h>
#include <Windows.h>
int main()
{
	SetConsoleOutputCP(1251);
	int i;
	printf("1.Enter adresses\n");
	printf("2.Delete adresses\n");
	printf("3.Search the list\n");
	printf("4.Print the list\n");
	printf("5.Quit\n");
	do {
		printf("Enter the number of your choice(1-5):");
		scanf("%d", &i);
		printf("\n");
	} while (i != 1 && i != 2 && i != 3 && i != 4 && i != 5);
	printf("Your choice is %d.", i);

	return 0;
}