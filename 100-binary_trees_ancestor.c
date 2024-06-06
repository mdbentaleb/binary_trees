#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to the lowest common ancestor node of the two given nodes
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *mm, *pp;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	mm = first->parent, pp = second->parent;
	if (first == pp || !mm || (!mm->parent && pp))
		return (binary_trees_ancestor(first, pop));
	else if (mm == second || !pp || (!pp->parent && mm))
		return (binary_trees_ancestor(mm, second));

	return (binary_trees_ancestor(mm, pp));
}
