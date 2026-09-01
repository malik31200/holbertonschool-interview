#include "search.h"
#include <math.h>

/**
 * linear_skip - Searches for a value in a sorted skip list
 * @list: Pointer to the head of the skip list
 * @value: Value to search for
 *
 * Return: Pointer to the node containing value, or NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current;
	skiplist_t *previous;

	if (list == NULL)
		return (NULL);

	current = list;
	previous = list;

	while (current->express != NULL && current->express->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
				current->express->index, current->express->n);
		previous = current->express;
		current = current->express;
	}

	if (current->express != NULL)
	{
		printf("Value checked at index [%lu] = [%d]\n",
				current->express->index, current->express->n);

		printf("Value found between indexes [%lu] and [%lu]\n",
				previous->index, current->express->index);

		current = previous;
		while (current != NULL && current->index <=
				current->express->index)
		{
			printf("Value checked at index [%lu] = [%d]\n",
					current->index, current->n);

			if (current->n == value)
				return (current);

			if (current->n > value)
				return (NULL);

			current = current->next;
		}
	}
	else
	{
		printf("Value found between indexes [%lu] and [%lu]\n",
				previous->index, previous->index);

		current = previous;
		while (current != NULL)
		{
			printf("Value checked at index [%lu] = [%d]\n",
					current->index, current->n);

			if (current->n == value)
				return (current);

			if (current->n > value)
				return (NULL);

			current = current->next;
		}
	}

	return (NULL);
}
