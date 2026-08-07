#include <stdio.h>

#include "menger.h"

/**
 * power_of_three - computes 3 raised to a level
 * @level: exponent
 *
 * Return: 3 to the power of level
 */
static int power_of_three(int level)
{
	int result;

	result = 1;
	while (level > 0)
	{
		result *= 3;
		level--;
	}

	return (result);
}

/**
 * is_hole - checks whether a cell belongs to the empty center
 * @row: row index
 * @col: column index
 *
 * Return: 1 if the cell must be empty, 0 otherwise
 */
static int is_hole(int row, int col)
{
	while (row > 0 || col > 0)
	{
		if (row % 3 == 1 && col % 3 == 1)
			return (1);
		row /= 3;
		col /= 3;
	}

	return (0);
}

/**
 * menger - draws a 2D Menger sponge
 * @level: sponge level
 */
void menger(int level)
{
	int size;
	int row;
	int col;

	if (level < 0)
		return;

	size = power_of_three(level);
	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			if (is_hole(row, col))
				putchar(' ');
			else
				putchar('#');
		}
		putchar('\n');
	}
}
