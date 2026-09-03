#include "sort.h"

/**
 * swap - Swaps two integers
 *
 * @a: First integer
 * @b: Second integer
 */
static void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * sift_down - Sifts an element down in a max heap
 *
 * @array: Array to modify
 * @heap_size: Current size of the heap
 * @root: Root index
 * @size: Total size of the array
 */
static void sift_down(int *array, size_t heap_size, size_t root, size_t size)
{
	size_t child;
	size_t largest;

	while (root * 2 + 1 < heap_size)
	{
		child = root * 2 + 1;
		largest = root;

		if (array[child] > array[largest])
			largest = child;

		if (child + 1 < heap_size &&
		    array[child + 1] > array[largest])
			largest = child + 1;

		if (largest == root)
			return;

		swap(&array[root], &array[largest]);
		print_array(array, size);
		root = largest;
	}
}

/**
 * heap_sort - Sorts an array using the Heap sort algorithm
 *
 * @array: Array of integers to sort
 * @size: Number of elements in the array
 */
void heap_sort(int *array, size_t size)
{
	size_t i;

	if (array == NULL || size < 2)
		return;

	i = size / 2;
	while (i > 0)
	{
		i--;
		sift_down(array, size, i, size);
	}

	i = size - 1;
	while (i > 0)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		sift_down(array, i, 0, size);
		i--;
	}
}
