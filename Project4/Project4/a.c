#include <stdio.h>
int main()
{
	int a;
	char c;
	c = getchar();
	printf("Input number between 1 and 5:");
	scanf("%d", &a);
	switch (c) {
	case '1': printf("One"); break;
	case '2': printf("Two"); break;
	case '3': printf("Three"); break;
	case '4': printf("Four"); break;
	case '5': printf("Five"); break;
	default: printf("Error!");
	}
	return 0;
}