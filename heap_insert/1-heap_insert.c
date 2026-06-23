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
 * get_last_node - finds last level order node parent
 */
static heap_t *get_last_parent(heap_t *root)
{
	heap_t *queue[1024];
	int i = 0, j = 0;
	heap_t *tmp;

	queue[j++] = root;

	while (i < j)
	{
		tmp = queue[i++];

		if (tmp->left && tmp->right)
		{
			queue[j++] = tmp->left;
			queue[j++] = tmp->right;
		}
		else
			return (tmp);

		if (tmp->left)
			queue[j++] = tmp->left;

		if (tmp->right)
			queue[j++] = tmp->right;
	}

	return (NULL);
}

/**
 * heap_insert - inserts a value in Max Binary Heap
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *node;
	heap_t *parent;

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

	parent = get_last_parent(*root);

	node->parent = parent;

	if (parent->left == NULL)
		parent->left = node;
	else
		parent->right = node;

	heapify_up(node);

	return (node);
}
