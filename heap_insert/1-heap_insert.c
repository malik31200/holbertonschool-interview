#include <stdlib.h>
#include "binary_trees.h"

/**
 * swap_values - swaps two integers
 * @a: first integer pointer
 * @b: second integer pointer
 *
 * Return: void
 */
static void swap_values(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * heapify_up - restores max heap property
 * @node: pointer to the node to bubble up
 *
 * Return: pointer to the node holding the inserted value after bubbling up
 */
static heap_t *heapify_up(heap_t *node)
{
	while (node->parent && node->n > node->parent->n)
	{
		swap_values(&node->n, &node->parent->n);
		node = node->parent;
	}

	return (node);
}

/**
 * get_last_parent - level order insertion parent
 * @root: pointer to the root of the heap
 *
 * Return: pointer to the parent where the next node should be attached
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
	}

	return (NULL);
}

/**
 * heap_insert - inserts value in max heap
 * @root: double pointer to the root of the heap
 * @value: value to insert
 *
 * Return: pointer to the inserted node, or NULL on failure
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
	{
		parent->left = node;
	}
	else
	{
		parent->right = node;
	}

	return (heapify_up(node));
}
