#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: pointer to the root node of the tree
 * Return: 0 if tree is NULL
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leav = 0;

	if (tree)
	{
		leav += (!tree->left && !tree->right) ? 1 : 0;
		leav += binary_tree_leaves(tree->left);
		leav += binary_tree_leaves(tree->right);
	}
	return (leav);
}
