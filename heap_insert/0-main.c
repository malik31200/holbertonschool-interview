#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * _binary_tree_delete - Deallocate a binary tree
 * @tree: Pointer to the root of the tree to delete
 */
static void _binary_tree_delete(binary_tree_t *tree)
{
    if (tree)
    {
        _binary_tree_delete(tree->left);
        _binary_tree_delete(tree->right);
        free(tree);
    }
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);
    if (root == NULL)
        return (1);

    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);

    printf("Root: %d\n", root->n);
    printf("Left child: %d\n", root->left->n);
    printf("Right child: %d\n", root->right->n);

    if (root->left->parent == root)
        printf("Parent link OK\n");

    _binary_tree_delete(root);

    return (0);
}