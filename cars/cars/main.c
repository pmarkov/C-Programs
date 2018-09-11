#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 256

void Print(int rides, int *ride_numbers);
void goToNext(char *line, int *i);
void readVehivclePaths(char *line, int *start_row, int *start_col, int *finish_row, int *finish_col,
	int *erliest_start, int *latest_finish);

int main()
{
	int start_row, start_col;
	int finish_row, finish_col;
	int earliest_start, latest_finish;
	int vehicle_count = 0;

	char line[MAX_LINE];

	FILE *fp = fopen("b_should_be_easy.in", "r");

	fgets(line, MAX_LINE, fp);

	while (fgets(line, MAX_LINE, fp))
	{
		readVehivclePaths(line, &start_row, &start_col, &finish_row, &finish_col,
			&earliest_start, &latest_finish);
		printf("%d %d %d %d %d %d\n", start_row, start_col, finish_row, finish_col, earliest_start, latest_finish);
	}

	system("pause");
	return 0;
}
void readVehivclePaths(char *line, int *start_row, int *start_col, int *finish_row, int *finish_col,
	int *earliest_start, int *latest_finish)
{
	int i;
	for (i = 0; line[i] != '\n', line[i] != '\0'; )
	{
		(*start_row) = atoi(&line[i]);

		goToNext(line, &i);
		(*start_col) = atoi(&line[i]);

		goToNext(line, &i);
		(*finish_row) = atoi(&line[i]);

		goToNext(line, &i);
		(*finish_col) = atoi(&line[i]);

		goToNext(line, &i);
		(*earliest_start) = atoi(&line[i]);

		goToNext(line, &i);
		(*latest_finish) = atoi(&line[i]);
		goToNext(line, &i);
	}
}
void goToNext(char *line, int *index)
{
	while (line[(*index)] != ' ' && line[(*index) + 1] != '\0')
		(*index)++;
	(*index)++;
}

void Print(int rides, int *ride_numbers)
{
	FILE *fWrite = fopen("result.txt", "w");
	int j;

	if (rides == 1)
	{
		fprintf(fWrite, "this vehicle is assigned 1 ride: [%d]", ride_numbers[0]);
	}
	else
	{
		fprintf(fWrite, "this vehicle is assigned %d rides: ", rides);
		fputc('[', fWrite);
		for (j = 0; j < rides; j++)
		{
			fputc(ride_numbers[j] + 48, fWrite);
			if (j + 1 < rides)
				fputc(',', fWrite);
		}
		fputc(']', fWrite);
	}
	fclose(fWrite);
}