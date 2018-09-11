#include <stdio.h>
#include <conio.h>
int main()
{
	int i;
	char c;
	c = 'a';
	for (i = 0; c != 'q'; i++) {
		printf("pass: %d\n", i);
		c = _getche();
	}


	return 0;
}