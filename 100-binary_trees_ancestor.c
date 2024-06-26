#include "binary_trees.h"

/**
* binary_tree_depth - Measures the depth of a node in a binary tree
* @node: Pointer to the node to measure the depth
*
* Return: The depth of the node, or 0 if node is NULL
*/
size_t binary_tree_depth(const binary_tree_t *node)
{
	size_t depth = 0;

	while (node != NULL && node->parent != NULL)
	{
		depth++;
		node = node->parent;
	}

	return (depth);
}

/**
* binary_trees_ancestor - Finds the lowest common ancestor of two nodes
* @first: Pointer to the first node
* @second: Pointer to the second node
*
* Return: Pointer to the lowest common ancestor node,
* or NULL if no common ancestor was found
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
	const binary_tree_t *second)
{
	size_t depth_first, depth_second;

	if (first == NULL || second == NULL)
		return (NULL);

	depth_first = binary_tree_depth(first);
	depth_second = binary_tree_depth(second);

	/* Move the deeper node up until both nodes are at the same depth */
	while (depth_first > depth_second)
	{
		first = first->parent;
		depth_first--;
	}

	while (depth_second > depth_first)
	{
		second = second->parent;
		depth_second--;
	}

	/* Move both nodes up until we find the common ancestor */
	while (first != NULL && second != NULL && first != second)
	{
		first = first->parent;
		second = second->parent;
	}

	return ((binary_tree_t *)first);
}
