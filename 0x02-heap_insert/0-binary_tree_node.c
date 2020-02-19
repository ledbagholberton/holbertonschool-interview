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

/**
 * preorder - goes through a binary tree using pre-order traversal
 * @last_node: double pointer to find the last node
 * @tree: pointer to the root
 * @level: level to print
 * @ref: reference to start
 * @flag: only work for first match
 * Return: no return
 **/
void preorder(heap_t *tree, int level, int ref, heap_t **last_node, int *flag)
{
	if (!tree)
		return;
	if (level == ref)
	{
		last_node[0] = tree;
	}
	if (level - 1 == ref && binary_tree_is_leaf(tree) == 1 && *flag == 0)
	{
		last_node[1] = tree;
		*flag = 1;
	}
	if (tree->left)
		preorder(tree->left, level, ref + 1, last_node, flag);
	if (tree->right)
		preorder(tree->right, level, ref + 1, last_node, flag);
}

/**
 * binary_tree_insert_left - inserts a node in the binary tree (left)
 * @parent: pointer to a parent node
 * @value: number value in the node inserted
 * Return: pointer to the new node
**/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *tmp, *node;

	if (!parent)
		return (NULL);
	tmp = parent->left;
	node = binary_tree_node(parent, value);
	parent->left = node;
	if (tmp != NULL)
	{
		node->left = tmp;
		tmp->parent = node;
	}
	return (node);
}

/**
 * binary_tree_insert_right - inserts a node in the binary tree (right)
 * @parent: pointer to a parent node
 * @value: number value in the node
 * Return: pointer to the new node inserted
**/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *tmp, *node;

	if (!parent)
		return (NULL);
	tmp = parent->right;
	node = binary_tree_node(parent, value);
	parent->right = node;
	if (tmp != NULL)
	{
		node->right = tmp;
		tmp->parent = node;
	}
	return (node);
}

/**
 * _height - measures the height of a binary tree
 * @tree: pointer to the node
 * Return: height of the tree from node
 **/
size_t _height(const binary_tree_t *tree)
{
	size_t left, right;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (0);
	right = _height(tree->right) + 1;
	left = _height(tree->left) + 1;
	if (left > right)
		return (left);
	else
		return (right);
}clear