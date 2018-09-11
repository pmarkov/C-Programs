#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *str = (char*)malloc(sizeof(char) * 100);

	if (str)
	{
		int i, j;

		for (i = 65, j = 0; i <= 90; i++, j++)
		{
			str[j] = i;
		}
		str[j] = '\0';
		printf("%s", str);
		free(str);
	}
	getchar();
	return 0;
}