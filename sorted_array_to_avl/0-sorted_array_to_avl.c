#include <stdlib.h>

#include "binary_trees.h"

/**
 * free_tree - frees a binary tree
 * @tree: tree to free
 */
static void free_tree(avl_t *tree)
{
	if (tree == NULL)
		return;

	free_tree(tree->left);
	free_tree(tree->right);
	free(tree);
}

/**
 * build_tree - builds a balanced AVL tree from a sorted array
 * @array: sorted array
 * @start: first index in the current range
 * @end: last index in the current range
 * @parent: parent node
 *
 * Return: pointer to the root of the subtree, or NULL on failure
 */
static avl_t *build_tree(int *array, size_t start, size_t end, avl_t *parent)
{
	avl_t *node;
	size_t middle;

	if (start > end)
		return (NULL);

	middle = start + (end - start) / 2;
	node = malloc(sizeof(*node));
	if (node == NULL)
		return (NULL);

	node->n = array[middle];
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	if (middle > start)
	{
		node->left = build_tree(array, start, middle - 1, node);
		if (node->left == NULL)
		{
			free_tree(node);
			return (NULL);
		}
	}

	if (middle < end)
	{
		node->right = build_tree(array, middle + 1, end, node);
		if (node->right == NULL)
		{
			free_tree(node);
			return (NULL);
		}
	}

	return (node);
}

/**
 * sorted_array_to_avl - builds an AVL tree from a sorted array
 * @array: pointer to the first element of the array
 * @size: number of elements in the array
 *
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (build_tree(array, 0, size - 1, NULL));
}
