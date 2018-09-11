#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
/*	char fname[30];
	printf("Enter file name: ");
	fgets(fname, 29, stdin);
	fname[strlen(fname) - 1] = '\0; */

	FILE *fp = fopen("file.dat", "ab+");
	
	if (fp == NULL) {
		printf("Error opening file");
		system("pause");
		exit(1);
	}

	FILE *temp = fopen("temp_file.dat", "wb");

	if (temp == NULL) {
		printf("Error opening file");
		system("pause");
		exit(1);
	}

	fclose(fp);
	fclose(temp);

	if (remove("file.dat") != 0) {
		printf("Error removing file\n");
	}
	if (rename("temp_file.dat", "file.dat") != 0) {
		printf("Error renaming file\n");
	}

	fp = fopen("file.dat", "ab+");
	if (fp == NULL) {
		printf("Error opening file2");
	}


	system("pause");
	return 0;
}