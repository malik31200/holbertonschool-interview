#include <stdlib.h>
#include "binary_trees.h"

/**
 * swap_values - swaps two integers
 * @a: first integer
 * @b: second integer
 */
static void swap_values(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * heapify_up - restores Max Heap property going up
 * @node: pointer to the node to move up
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
 * get_size - returns number of nodes in heap
 * @root: root of heap
 *
 * Return: size of heap
 */
static size_t get_size(const heap_t *root)
{
	if (root == NULL)
		return (0);

	return (1 + get_size(root->left) + get_size(root->right));
}

/**
 * get_node - finds insertion parent using index
 * @root: root of heap
 * @index: position in array form
 *
 * Return: pointer to parent node
 */
static heap_t *get_node(heap_t *root, size_t index)
{
	size_t bits = 0;

	if (root == NULL || index == 0)
		return (NULL);

	while ((1UL << bits) <= index)
		bits++;

	bits--;

	while (bits > 0)
	{
		bits--;

		if (index & (1UL << bits))
			root = root->right;
		else
			root = root->left;
	}

	return (root);
}

/**
 * heap_insert - inserts a value in Max Binary Heap
 * @root: double pointer to root
 * @value: value to insert
 *
 * Return: pointer to inserted node, or NULL
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *node;
	heap_t *parent;
	size_t size;

	if (root == NULL)
		return (NULL);

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	size = get_size(*root) + 1;
	parent = get_node(*root, size / 2);

	node = binary_tree_node(parent, value);
	if (node == NULL)
		return (NULL);

	if (parent->left == NULL)
		parent->left = node;
	else
		parent->right = node;

	heapify_up(node);

	return (node);
}
