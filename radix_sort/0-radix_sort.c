#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * get_max - finds the maximum value in an array
 * @array: array of integers
 * @size: number of elements
 *
 * Return: maximum value
 */
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort - sorts array by a specific digit using counting sort
 * @array: array of integers
 * @size: number of elements
 * @exp: digit position (1, 10, 100, ...)
 * @output: temporary output buffer
 */
void counting_sort(int *array, size_t size, int exp, int *output)
{
	int count[10] = {0};
	size_t i;
	int digit;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = size; i > 0; i--)
	{
		digit = (array[i - 1] / exp) % 10;
		output[count[digit] - 1] = array[i - 1];
		count[digit]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
}

/**
 * radix_sort - sorts an array of integers using LSD radix sort
 * @array: array of integers
 * @size: number of elements
 */
void radix_sort(int *array, size_t size)
{
	int *output;
	int max;
	int exp;

	if (size < 2)
		return;
	output = malloc(sizeof(int) * size);
	if (!output)
		return;
	max = get_max(array, size);
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort(array, size, exp, output);
		print_array(array, size);
	}
	free(output);
}
