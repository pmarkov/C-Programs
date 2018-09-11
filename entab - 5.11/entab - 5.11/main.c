#include <stdio.h>

/*Заменя низ от шпации с минимален брой табулации и шпации, 
така че да се запази същото празно пространство.(1 табулация = 8 шпации)*/

int main(int argc, char *argv[])
{
	char line[256];
	char line2[256];
	char ch;
	int spacecount = 0;
	int tabcount = 0;
	int i = 0, j = 0;


	while (fgets(line, 255, stdin) != NULL)
	{
		i = 0;
		j = 0;
		while (line[i] == ' ')
		{
			spacecount++;
			i++;
		}
		if (spacecount >= 8)
		{
			tabcount = spacecount / 8;
			spacecount %= 8;
			while (tabcount-- > 0)
				line2[j++] = '\t';
			while (spacecount-- > 0)
				line2[j++] = ' ';
			while (line[i] != '\n')
				line2[j++] = line[i++];
			line2[j] = '\0';
			printf("%s\n", line2);
		}
		else
			printf("%s", line);
	}

	getchar();
	return 0;
}