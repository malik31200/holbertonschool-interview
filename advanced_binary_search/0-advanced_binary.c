
#include <stdio.h>
#include "search_algos.h"

/**
 * print_array - Prints the elements of an array
 * @array: Pointer to the first element
 * @size: Number of elements to print
 */
static void print_array(int *array, size_t size)
{
	size_t i;

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i < size - 1)
			printf(", ");
	}
	printf("\n");
}

/**
 * advanced_binary_recursive - Searches for the first occurrence
 * @array: Pointer to the first element of the subarray
 * @size: Number of elements in the subarray
 * @value: Value to search for
 * @offset: Starting index in the original array
 *
 * Return: First index of value, or -1
 */
static int advanced_binary_recursive(int *array, size_t size,
				     int value, size_t offset)
{
	size_t mid;

	if (size == 0)
		return (-1);

	print_array(array, size);

	mid = (size - 1) / 2;

	if (array[mid] == value)
	{
		if (mid == 0 || array[mid - 1] != value)
			return ((int)(offset + mid));

		return (advanced_binary_recursive(array, mid, value, offset));
	}

	if (array[mid] < value)
		return (advanced_binary_recursive(array + mid + 1,
						  size - mid - 1,
						  value, offset + mid + 1));

	return (advanced_binary_recursive(array, mid, value, offset));
}

/**
 * advanced_binary - Searches for the first occurrence of a value
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: First index where value is found, or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (advanced_binary_recursive(array, size, value, 0));
}
