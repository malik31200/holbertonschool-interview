#include "binary_trees.h"
#include <stdlib.h>

/**
 * _binary_tree_delete - Frees a binary tree.
 * @tree: Pointer to the root node.
 */
void _binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	_binary_tree_delete(tree->left);
	_binary_tree_delete(tree->right);
	free(tree);
}

/**
 * insert_level_order - Inserts a value at the next available position.
 * @root: Pointer to the root node.
 * @value: Value to insert.
 *
 * Return: Pointer to the inserted node, or NULL on failure.
 */
static heap_t *insert_level_order(heap_t **root, int value)
{
	heap_t **queue;
	heap_t *node;
	size_t size = 0, head = 0, tail = 0;

	if (*root == NULL)
	{
		*root = malloc(sizeof(heap_t));
		if (*root == NULL)
			return (NULL);

		(*root)->n = value;
		(*root)->parent = NULL;
		(*root)->left = NULL;
		(*root)->right = NULL;
		return (*root);
	}

	queue = malloc(sizeof(heap_t *) * 1024);
	if (queue == NULL)
		return (NULL);

	queue[tail++] = *root;
	while (head < tail)
	{
		node = queue[head++];

		if (node->left == NULL)
		{
			node->left = malloc(sizeof(heap_t));
			if (node->left == NULL)
				break;

			node->left->n = value;
			node->left->parent = node;
			node->left->left = NULL;
			node->left->right = NULL;
			free(queue);
			return (node->left);
		}
		queue[tail++] = node->left;

		if (node->right == NULL)
		{
			node->right = malloc(sizeof(heap_t));
			if (node->right == NULL)
				break;

			node->right->n = value;
			node->right->parent = node;
			node->right->left = NULL;
			node->right->right = NULL;
			free(queue);
			return (node->right);
		}
		queue[tail++] = node->right;
		size++;
		(void)size;
	}
	free(queue);
	return (NULL);
}

/**
 * _array_to_heap - Builds a max heap from an array.
 * @array: Array of integers.
 * @size: Number of elements.
 *
 * Return: Pointer to the heap root, or NULL on failure.
 */
heap_t *_array_to_heap(int *array, size_t size)
{
	heap_t *root = NULL;
	heap_t *node;
	size_t i;
	int tmp;

	if (array == NULL || size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		node = insert_level_order(&root, array[i]);
		if (node == NULL)
		{
			_binary_tree_delete(root);
			return (NULL);
		}

		while (node->parent != NULL && node->n > node->parent->n)
		{
			tmp = node->n;
			node->n = node->parent->n;
			node->parent->n = tmp;
			node = node->parent;
		}
	}
	return (root);
}
