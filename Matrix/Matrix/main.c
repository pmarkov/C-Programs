#include <stdio.h>
#include <stdlib.h>

void error(char *msg)
{
	perror(msg);
	exit(1);
}

int main()
{
	int	n = 5;
	int **matrix = malloc(n * sizeof(int*));
	if (!matrix)
	{
		error("Couldn't allocate rows");
	}

	for (int i = 0; i < n; i++)
	{
		matrix[i] = malloc(n * sizeof(int));
		if (!matrix[i])
		{
			error("Couldn't allocate columns");
		}
	}
	int row, col, count = 1;

	for (row = 0; row < n; row++)
	{
		for (col = 0; col < n; col++, count++)
		{
			matrix[row][col] = count;
			printf("%d ", matrix[row][col]);
		}
		printf("\n");
	}
	for (row = 0; row < n; row++)
	{
		free(matrix[row]);
	}
	free(matrix);
	
	getchar();

	return 0;
}