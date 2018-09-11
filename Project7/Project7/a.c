#include <stdio.h>
#include <Windows.h>
#include <string.h>
int main()
{
	SetConsoleOutputCP(1251);
	char str[80], bigstr[1000]="";
	
	for( ; ; ) {
		printf("Въведете низ: ");
		gets(str);
		if (!strcmp(str, "quit")) break;
		strcat(str, "\n");
		if (strlen(bigstr) + strlen(str) >= 1000) break;
		strcat(bigstr, str);
	}
	printf(bigstr);
	getchar();

	return 0;
}