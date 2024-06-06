#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: 0 if tree is NULL
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t sz = 0;

	if (tree)
	{
		sz += 1;
		sz += binary_tree_size(tree->left);
		sz += binary_tree_size(tree->right);
	}
	return (sz);
}
