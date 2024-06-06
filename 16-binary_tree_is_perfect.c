#include "binary_trees.h"

int binary_tree_is_perfect(const binary_tree_t *tree);
int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level);
const binary_tree_t *get_leaf(const binary_tree_t *tree);
size_t depth(const binary_tree_t *tree);
unsigned char is_leaf(const binary_tree_t *node);



/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: int
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_perfect_recursive(tree, depth(get_leaf(tree)), 0));
}



/**
 * depth - returns the depth of a given node in a binary tree
 * @tree: pointer to the node to measure the depth of
 * Return: depth of node
 */

size_t depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + depth(tree->parent) : 0);
}


/**
 * get_leaf - returns a leaf of a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: pointer to the first encountered leaf
 */

const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree) == 1)
		return (tree);
	return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}


/**
 * is_perfect_recursive - checks if a binary tree is perfect recursively
 * @tree: pointer to the root node of the tree to check
 * @leaf_depth: depth of one leaf in the binary tree
 * @level: level of current node
 * Return: int
 */

int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level)
{
	if (is_leaf(tree))
		return (level == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
		is_perfect_recursive(tree->right, leaf_depth, level + 1));
}


/**
 * is_leaf - checks if a node is a leaf of a binary tree
 * @node: pointer to the node
 * Return:  If the node is a leaf, 1, otherwise, 0
 */
unsigned char is_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}
