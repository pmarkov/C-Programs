#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char line[256];
	long linecount = 0;
	int c, except = 0, number = 0;

	while (--argc > 0 && (*++argv)[0] == '-')
	{
		while (c = *++argv[0])
		{
			switch (c)
			{
			case 'x':
				except = 1;
				break;
			case 'n':
				number = 1;
				break;
			default:
				printf("find: illegal option %c\n", c);
				argc = 0;
				break;
			}
		}
	}
	while (fgets(line, 255, stdin) != NULL)
	{
		linecount++;
		if ((strstr(line, *argv) != NULL) != except)
		{
			if (number)
				printf("%ld: ", linecount);
			printf("%s\n", line);
		}
	}
	return 0;
}