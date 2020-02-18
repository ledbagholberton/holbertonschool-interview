#include "binary_trees.h"
/**
 * binary_tree_node - creates a node in the binary tree
 * @parent: pointer to a parent node
 * @value: number value in the node
 * Return: pointer to the new node
**/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);
	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
