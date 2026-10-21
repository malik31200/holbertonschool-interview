
#include "binary_trees.h"
#include <stdlib.h>

/**
 * heap_size - Counts the nodes in a heap.
 * @root: Pointer to the root node.
 *
 * Return: Number of nodes.
 */
static size_t heap_size(heap_t *root)
{
	size_t left, right;

	if (root == NULL)
		return (0);

	left = heap_size(root->left);
	right = heap_size(root->right);

	return (1 + left + right);
}

/**
 * get_last_node - Finds the last node in level order.
 * @root: Pointer to the root node.
 * @index: Index of the node to find.
 * @current: Current index in level order.
 *
 * Return: Pointer to the requested node, or NULL.
 */
static heap_t *get_last_node(heap_t *root, size_t index,
			     size_t *current)
{
	heap_t *node;

	if (root == NULL)
		return (NULL);

	if (*current == index)
		return (root);

	(*current)++;
	node = get_last_node(root->left, index, current);
	if (node != NULL)
		return (node);

	node = get_last_node(root->right, index, current);
	return (node);
}

/**
 * sift_down - Restores the max heap property.
 * @root: Pointer to the root node.
 */
static void sift_down(heap_t *root)
{
	heap_t *largest;
	int tmp;

	if (root == NULL)
		return;

	largest = root;

	if (root->left && root->left->n > largest->n)
		largest = root->left;

	if (root->right && root->right->n > largest->n)
		largest = root->right;

	if (largest != root)
	{
		tmp = root->n;
		root->n = largest->n;
		largest->n = tmp;
		sift_down(largest);
	}
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap.
 * @root: Double pointer to the heap root.
 *
 * Return: The extracted value, or 0 on failure.
 */
int heap_extract(heap_t **root)
{
	heap_t *last;
	size_t size, current = 0;
	int value;

	if (root == NULL || *root == NULL)
		return (0);

	value = (*root)->n;
	size = heap_size(*root);

	if (size == 1)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	last = get_last_node(*root, size - 1, &current);
	if (last == NULL)
		return (0);

	(*root)->n = last->n;

	if (last->parent->left == last)
		last->parent->left = NULL;
	else
		last->parent->right = NULL;

	free(last);
	sift_down(*root);

	return (value);
}
