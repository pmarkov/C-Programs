#include <stdio.h>
#include <string.h>
#include <fcntl.h>

void replace(int fR);

int main()
{
	char fname[256];
	char ch;
	int fileDesc;

	printf("Enter a file for reading: ");
	if (fgets(fname, 255, stdin) == NULL)
	{
		printf("Error with file name!");
		return 1;
	}
	fname[strlen(fname) - 1] = '\0';

	if ((fileDesc = open(fname, _O_TEXT | O_RDONLY)) < 0)
	{
		printf("Error with opening file!");
		system("pause");
		return 1;
	}

	replace(fileDesc);

	if (close(fileDesc) < 0)
		return 1;

	printf("\n");
	system("pause");
	return 0;
}
void replace(int fR)
{
	char buffer[256];
	char fname2[256];
	char ch;
	int fW;
	int w;

	printf("Enter a file for result: ");
	if (fgets(fname2, 255, stdin) == NULL)
	{
		printf("Error with file name!");
		return;
	}
	fname2[strlen(fname2) - 1] = '\0';

	if ((fW = open(fname2, _O_TEXT | O_WRONLY | O_CREAT)) < 0)
	{
		printf("Error with opening file!");
		return;
	}

	while (read(fR, &ch, 1) > 0)
	{	
		if (ch == '2')
		{
			w = write(fW, "13", 2);
		}
		else
			w = write(fW, &ch, 1);
		if (w < 0)
		{
			printf("Error with writing in file!");
			return;
		}
	}

/*	for(int i = 0; buffer[i] != EOF; i++)
	{
		int r = read(fR, buffer, 1);
		if (r < 0)
		{
			printf("Error");
			return;
		}
		buffer[r] = '\0';
		if (!strcmp("2", buffer))
		{
			w = write(fW, "13", 2);
		}
		else
			w = write(fW, buffer, 1);
		if (w < 0)
		{
			printf("Error");
			return;
		}
	} */

	if (close(fW) < 0)
		return;
}