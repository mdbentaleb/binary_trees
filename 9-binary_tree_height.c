#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree.
 *
 * @tree: pointer to the root node of the tree to measure the height
 * Return: 0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t lf = 0, rg = 0;

		lf = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		rg = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return ((lf > rg) ? lf : rg);
	}
	return (0);
}
