#include "sandpiles.h"

/**
 * is_stable - checks if a sandpile is stable
 * @grid: 3x3 grid
 *
 * Return: 1 if stable, 0 otherwise
 */
static int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}
	}
	return (1);
}

/**
 * print_grid - prints a 3x3 grid
 * @grid: grid to print
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * toppling - performs one sandpile iteration
 * @grid: 3x3 grid
 */
static void toppling(int grid[3][3])
{
	int i, j;
	int tmp[3][3] = {0};

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				tmp[i][j] -= 4;
				if (i > 0)
					tmp[i - 1][j]++;
				if (i < 2)
					tmp[i + 1][j]++;
				if (j > 0)
					tmp[i][j - 1]++;
				if (j < 2)
					tmp[i][j + 1]++;
			}
		}
	}

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid[i][j] += tmp[i][j];
}

/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: first grid
 * @grid2: second grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];

	while (!is_stable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		toppling(grid1);
	}
}
