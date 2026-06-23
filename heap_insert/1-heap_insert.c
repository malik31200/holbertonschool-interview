#include <stdlib.h>
#include "binary_trees.h"

/**
 * swap_values - swaps two integers
 */
static void swap_values(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * heapify_up - restores max heap property
 */
static void heapify_up(heap_t *node)
{
	while (node->parent && node->n > node->parent->n)
	{
		swap_values(&node->n, &node->parent->n);
		node = node->parent;
	}
}

/**
 * heap_insert - inserts a value into Max Binary Heap
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *node;
	heap_t *parent;
	heap_t *queue[1024];
	int front = 0, back = 0;

	if (root == NULL)
		return (NULL);

	node = binary_tree_node(NULL, value);
	if (node == NULL)
		return (NULL);

	if (*root == NULL)
	{
		*root = node;
		return (node);
	}

	queue[back++] = *root;

	while (front < back)
	{
		parent = queue[front++];

		if (parent->left)
			queue[back++] = parent->left;
		else
		{
			parent->left = node;
			node->parent = parent;
			heapify_up(node);
			return (node);
		}

		if (parent->right)
			queue[back++] = parent->right;
		else
		{
			parent->right = node;
			node->parent = parent;
			heapify_up(node);
			return (node);
		}
	}

	return (node);
}
