#include "slide_line.h"

/**
 * reverse_line - reverses an array of integers in place
 * @line: array to reverse
 * @size: number of elements in @line
 */
static void reverse_line(int *line, size_t size)
{
	size_t i;
	size_t j;
	int tmp;

	if (size < 2)
		return;

	for (i = 0, j = size - 1; i < j; i++, j--)
	{
		tmp = line[i];
		line[i] = line[j];
		line[j] = tmp;
	}
}

/**
 * slide_left - slides and merges a line to the left
 * @line: array to modify
 * @size: number of elements in @line
 */
static void slide_left(int *line, size_t size)
{
	size_t read;
	size_t write;
	int merged[size];
	int result[size];

	for (read = 0; read < size; read++)
	{
		result[read] = 0;
		merged[read] = 0;
	}

	for (read = 0, write = 0; read < size; read++)
	{
		if (line[read] == 0)
			continue;

		if (write > 0 && result[write - 1] == line[read]
			&& merged[write - 1] == 0)
		{
			result[write - 1] *= 2;
			merged[write - 1] = 1;
		}
		else
		{
			result[write] = line[read];
			merged[write] = 0;
			write++;
		}
	}

	for (read = 0; read < size; read++)
		line[read] = result[read];
}

/**
 * slide_line - slides and merges an array of integers
 * @line: array to modify
 * @size: number of elements in @line
 * @direction: slide direction
 *
 * Return: 1 on success, 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (line == NULL || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
		return (0);

	if (size == 0)
		return (1);

	if (direction == SLIDE_RIGHT)
		reverse_line(line, size);

	slide_left(line, size);

	if (direction == SLIDE_RIGHT)
		reverse_line(line, size);

	return (1);
}
