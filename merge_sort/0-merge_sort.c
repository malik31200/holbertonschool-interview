#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void sort(int *array, int *tmp, size_t left, size_t right);
void merge(int *array, int *tmp, size_t left, size_t mid, size_t right);

/**
 * print_subarray - prints a subarray
 * @array: array of integers
 * @left: start index
 * @right: end index
 */
void print_subarray(const int *array, size_t left, size_t right)
{
	size_t i;

	for (i = left; i < right; i++)
	{
		if (i > left)
			printf(", ");
		printf("%d", array[i]);
	}
}

/**
 * merge - merges two sorted subarrays
 * @array: array of integers
 * @tmp: temporary buffer
 * @left: start index of left subarray
 * @mid: start index of right subarray
 * @right: end index
 */
void merge(int *array, int *tmp, size_t left, size_t mid, size_t right)
{
	size_t i = left;
	size_t j = mid;
	size_t k = left;

	printf("Merging...\n");
	printf("[left]: ");
	print_subarray(array, left, mid);
	printf("\n[right]: ");
	print_subarray(array, mid, right);
	while (i < mid && j < right)
	{
		if (array[i] <= array[j])
			tmp[k++] = array[i++];
		else
			tmp[k++] = array[j++];
	}
	while (i < mid)
		tmp[k++] = array[i++];
	while (j < right)
		tmp[k++] = array[j++];
	for (i = left; i < right; i++)
		array[i] = tmp[i];
	printf("\n[Done]: ");
	print_subarray(array, left, right);
	printf("\n");
}

/**
 * sort - recursively sorts a subarray
 * @array: array of integers
 * @tmp: temporary buffer
 * @left: start index
 * @right: end index
 */
void sort(int *array, int *tmp, size_t left, size_t right)
{
	size_t mid;

	if (right - left < 2)
		return;
	mid = left + (right - left) / 2;
	sort(array, tmp, left, mid);
	sort(array, tmp, mid, right);
	merge(array, tmp, left, mid, right);
}

/**
 * merge_sort - sorts an array of integers using merge sort
 * @array: array of integers
 * @size: number of elements
 */
void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (size < 2)
		return;
	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		return;
	sort(array, tmp, 0, size);
	free(tmp);
}
