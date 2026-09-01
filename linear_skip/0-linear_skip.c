#include "search.h"

/**
 * search_range - Search for a value between two nodes
 * @start: First node to search from
 * @end: Last node of the search range
 * @value: Value to find
 *
 * Return: Pointer to the node containing value, or NULL
 */
static skiplist_t *search_range(skiplist_t *start, skiplist_t *end, int value)
{
	skiplist_t *current;

	current = start;
	while (current != NULL)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       current->index, current->n);

		if (current->n == value)
			return (current);

		if (current == end || current->n > value)
			break;

		current = current->next;
	}

	return (NULL);
}

/**
 * linear_skip - Searches for a value in a sorted skip list
 * @list: Pointer to the head of the skip list
 * @value: Value to search for
 *
 * Return: Pointer to the node containing value, or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current;
	skiplist_t *end;

	if (list == NULL)
		return (NULL);

	current = list;

	while (current->express != NULL && current->express->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       current->express->index, current->express->n);
		current = current->express;
	}

	if (current->express != NULL)
	{
		end = current->express;
		printf("Value checked at index [%lu] = [%d]\n",
		       end->index, end->n);
	}
	else
	{
		end = current;
		while (end->next != NULL)
			end = end->next;
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
	       current->index, end->index);

	return (search_range(current, end, value));
}
