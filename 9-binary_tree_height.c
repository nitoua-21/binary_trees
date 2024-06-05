#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: height of the tree
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_hight = 0;
	size_t right_height = 0;

	if (tree == NULL)
		return (0);

	left_hight = tree->left ? binary_tree_height(tree->left) + 1 : 0;
	right_height = tree->right ? binary_tree_height(tree->right) + 1 : 0;

	return (left_hight > right_height ? left_hight : right_height);
}
