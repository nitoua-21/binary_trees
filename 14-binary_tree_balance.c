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

	left_hight = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (1 + (left_hight > right_height ? left_hight : right_height));
}


/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: int
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}
