#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createColors(FILE *fp);
void readColors(FILE *fp);
void startPaint(double kilograms, double red, double green, double blue);
void searchColorNo(FILE *fp, char *colorNo, double *required_red,
	double *required_green, double *required_blue);
void currentRBG(FILE *fpRed, FILE *fpGreen, FILE *fpBlue);

int main()
{
	FILE *fpR;

	double red = 850.30;
	double green = 430;
	double blue = 740.50;
	double kilograms, required_red, required_green, required_blue;
	char colorNo[20];

/*	if ((fpR = fopen("colors.dat", "wb")) == NULL)
	{
		exit(1);
	}
	createColors(fpR);
	fclose(fpR); 

	if ((fpR = fopen("red.dat", "wb")) == NULL)
	{
		exit(3);
	}
	fwrite(&red, sizeof(double), 1, fpR);
	fclose(fpR);

	if ((fpR = fopen("green.dat", "wb")) == NULL)
	{
		exit(3);
	}
	fwrite(&green, sizeof(double), 1, fpR);
	fclose(fpR);

	if ((fpR = fopen("blue.dat", "wb")) == NULL)
	{
		exit(3);
	}
	fwrite(&blue, sizeof(double), 1, fpR);
	fclose(fpR); */

	if ((fpR = fopen("colors.dat", "rb")) == NULL)
	{
		exit(2);
	}
	readColors(fpR);

	printf("The number of required colour: ");
	fgets(colorNo, 20, stdin);
	colorNo[strlen(colorNo) - 1] = '\0';
	rewind(fpR);
	searchColorNo(fpR, colorNo, &required_red, &required_green, &required_blue);
	fclose(fpR);

	printf("How many kilograms do you want to make?\n");
	scanf("%lf", &kilograms);
	startPaint(kilograms, required_red, required_green, required_blue);


	system("pause");
	return 0;
}
void createColors(FILE *fp)
{
	int count;
	char colorNo[20];
	char colorName[20];
	double red, green, blue;

	printf("How many colors?");
	scanf("%d", &count);

	for (int i = 0; i < count; i++)
	{
		printf("\nEnter color %d number: ", i + 1);
		scanf("%s", colorNo);
		fwrite(colorNo, sizeof(colorNo), 1, fp);

		printf("\nEnter color %d name: ", i + 1);
		scanf("%s", colorName);
		fwrite(colorName, sizeof(colorName), 1, fp);

		printf("\nEnter red consistancy: ");
		scanf("%lf", &red);
		fwrite(&red, sizeof(double), 1, fp);

		printf("\nEnter green consistancy: ");
		scanf("%lf", &green);
		fwrite(&green, sizeof(double), 1, fp);

		printf("\nEnter blue consistancy: ");
		scanf("%lf", &blue);
		fwrite(&blue, sizeof(double), 1, fp);
	}
}
void readColors(FILE *fp)
{
	double red, green, blue;
	char colorNo[20];
	char colorName[20];

	while (1)
	{
		if (fread(colorNo, sizeof(colorNo), 1, fp) == 0)
			break;

		printf("Color's number is: %s\n", colorNo);

		fread(colorName, sizeof(colorName), 1, fp);
		printf("Color's name is: %s\n", colorName);

		fread(&red, sizeof(double), 1, fp);
		printf("Consistency of red paint is: %.2lf\n", red);

		fread(&green, sizeof(double), 1, fp);
		printf("Consistency of green paint is: %.2lf\n", green);

		fread(&blue, sizeof(double), 1, fp);
		printf("Consistency of blue paint is: %.2lf\n", blue);

		printf("\n\n");
	}
}
void searchColorNo(FILE *fp, char *colorNo, double *required_red,
	double *required_green, double *required_blue)
{
	char currColorNo[20];
	char currColorName[20];

	while (1)
	{
		if (fread(currColorNo, sizeof(currColorNo), 1, fp) == 0)
		{
			printf("Unrecognized color number");
			return;
		}
		else if (!strcmp(currColorNo, colorNo))
		{
			fread(currColorName, sizeof(currColorName), 1, fp);
			fread(required_red, sizeof(double), 1, fp);
			fread(required_green, sizeof(double), 1, fp);
			fread(required_blue, sizeof(double), 1, fp);
			return;
		}
		else
		{
			fseek(fp, sizeof(currColorNo) + 3 * sizeof(double), SEEK_CUR);
		}
	}
}
void startPaint(double kilograms, double red, double green, double blue)
{
	FILE *fpRed, *fpGreen, *fpBlue;

	double currRed, currGreen, currBlue;
	int flag = 0;

	if ((fpRed = fopen("red.dat", "rb+")) == NULL)
	{
		exit(3);
	}
	if ((fpGreen = fopen("green.dat", "rb+")) == NULL)
	{
		exit(3);
	}
	if ((fpBlue = fopen("blue.dat", "rb+")) == NULL)
	{
		exit(3);
	}

	fread(&currRed, sizeof(double), 1, fpRed);
	fread(&currGreen, sizeof(double), 1, fpGreen);
	fread(&currBlue, sizeof(double), 1, fpBlue);
	rewind(fpRed);
	rewind(fpGreen);
	rewind(fpBlue);

	if (currRed >= (red * kilograms)) {
		currRed -= (red * kilograms);
		fwrite(&currRed, sizeof(double), 1, fpRed);
	}
	else {
		printf("Not enough red paint\n");
		flag = 1;
	}
	if (currGreen >= (green * kilograms)) {
		currGreen -= (green * kilograms);
		fwrite(&currGreen, sizeof(double), 1, fpGreen);
	}
	else {
		printf("Not enough green paint\n");
		flag = 1;
	}
	if (currBlue >= (blue * kilograms)) {
		currBlue -= (blue * kilograms);
		fwrite(&currBlue, sizeof(double), 1, fpBlue);
	}
	else {
		printf("Not enough blue paint\n");
		flag = 1;
	}
	if (flag == 1)
	{
		printf("The paint couldn't be made\n\n");
	}
	else
		printf("The paint was made successfully\n\n");

	rewind(fpRed);
	rewind(fpGreen);
	rewind(fpBlue);
	currentRBG(fpRed, fpGreen, fpBlue);

	fclose(fpRed);
	fclose(fpGreen);
	fclose(fpBlue);
}
void currentRBG(FILE *fpRed, FILE *fpGreen, FILE *fpBlue)
{
	double red, green, blue;

	fread(&red, sizeof(double), 1, fpRed);
	fread(&green, sizeof(double), 1, fpGreen);
	fread(&blue, sizeof(double), 1, fpBlue);

	printf("Current quantity of red is %.2lf\n", red);
	printf("Current quantity of green is %.2lf\n", green);
	printf("Current quantity of blue is %.2lf\n", blue);
}