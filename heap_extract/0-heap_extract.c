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
	if (root == NULL)
		return (0);

	return (1 + heap_size(root->left) + heap_size(root->right));
}

/**
 * get_last_node - Finds a node by its level-order index.
 * @root: Pointer to the root node.
 * @index: Index of the node to find.
 *
 * Return: Pointer to the node, or NULL.
 */
static heap_t *get_last_node(heap_t *root, size_t index)
{
	heap_t **queue;
	heap_t *node;
	size_t size, head = 0, tail = 0, current = 0;

	if (root == NULL)
		return (NULL);

	size = heap_size(root);
	queue = malloc(sizeof(heap_t *) * size);
	if (queue == NULL)
		return (NULL);

	queue[tail++] = root;

	while (head < tail)
	{
		node = queue[head++];

		if (current == index)
		{
			free(queue);
			return (node);
		}
		current++;

		if (node->left != NULL)
			queue[tail++] = node->left;

		if (node->right != NULL)
			queue[tail++] = node->right;
	}

	free(queue);
	return (NULL);
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

	if (root->left != NULL && root->left->n > largest->n)
		largest = root->left;

	if (root->right != NULL && root->right->n > largest->n)
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
 * Return: Extracted value, or 0 on failure.
 */
int heap_extract(heap_t **root)
{
	heap_t *last;
	heap_t *parent;
	int value;
	size_t size;

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

	last = get_last_node(*root, size - 1);
	if (last == NULL || last->parent == NULL)
		return (0);

	(*root)->n = last->n;
	parent = last->parent;

	if (parent->left == last)
		parent->left = NULL;
	else
		parent->right = NULL;

	free(last);
	sift_down(*root);

	return (value);
}
