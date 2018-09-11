#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int max(FILE *);
void cpy2(FILE *);

int main()
{
	FILE *fp;
	int mn;

	if (!(fp = fopen("D:\\Tt\\Kapa.txt", "rt")))
	{
		printf("the file doesn't exists");
		return 1;
	}
	if (!(mn = max(fp))) {
		printf("there are no negative numbers in the file");
	}
	else
		printf("the max negative number is: %d", mn);
	rewind(fp);
	cpy2(fp);
	fclose(fp);

	getchar();
	return 0;
}
int max(FILE *inp)
{
	int next;
	int maxneg = 0;
	for (; fscanf(inp,"%d", &next) != EOF;)
	{
		if (next < 0) {
			if (!maxneg)
				maxneg = next;
			else if (maxneg < next)
					maxneg = next;
		}
	}
	return maxneg;
}
void cpy2(FILE *inp)
{
	FILE *output;
	char fname[256];
	char next;
	
	printf("\n\nenter the file where you want to copy the data: ");
	if (!fgets(fname, 256, stdin)) {
		printf("\nerror with the file name");
		return;
	}
	fname[strlen(fname) - 1] = '\0';
	if (!(output = fopen(fname, "w")))
	{
		printf("\nerror opening the file");
		return;
	}

	while ((next = fgetc(inp)) != EOF) {
		if (next == '2') 
			next = '4';
		if (fputc(next, output) == EOF)
		{
			printf("Error in file writing");
			return;
		}
	}
	fclose(output);
}