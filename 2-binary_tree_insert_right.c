#include "binary_trees.h"

/**
* binary_tree_insert_right - inserts a node as the right-child of another node
* @parent: pointer to the node to insert the right-child in
* @value: value to store in the new node
*
* Return: pointer to the created node
* or NULL on failure or if parent is NULL
*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node = NULL;

	if (parent == NULL)
		return (NULL);

	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);
	node->parent = parent;
	node->right = parent->right;
	node->left = NULL;
	node->n = value;

	if (parent->right != NULL)
		parent->right->parent = node;

	parent->right = node;

	return (node);
}
