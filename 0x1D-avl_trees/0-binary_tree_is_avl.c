#include "binary_trees.h"
/**
 * binary_tree_is_avl - Determine if tree is AVL
 * @tree: pointer to the root
 * Return: 1 if tree is AVL / 0 otherwise
 **/
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int a = 0, b = 0, c = 0, hleft = 0, hright = 0, okh = 0, dh;
	binary_tree_t *root;

	root = (binary_tree_t *)tree;
	if (!root)
		return (0);
	a = binary_tree_is_bst(root);
	if (!root->left && !root->right)
		return (1);
	else
	{
		if (root->left)
		{
			b = binary_tree_is_bst(root->left);
			hleft = binary_tree_height(root->left);
		}
		if (root->right)
		{
			c = binary_tree_is_bst(root->right);
			hright = binary_tree_height(root->right);
		}
		dh = hleft - hright;
		if (dh < 0)
			dh = -dh;
		if (dh >= 1)
			okh = 0;
		else
			okh = 1;
	}
	return (a & b & c & okh);
}

/**
 * preorder_max_min - goes through a binary tree using pre-order traversal
 * @value: value[0] max value, value[1] min value
 * @tree: pointer to the root
 * Return: no return
 **/
void preorder_max_min(const binary_tree_t *tree, int *value)
{
	if (!tree)
		return;
	if (value[0] < tree->n)
		value[0] = tree->n;
	if (value[1] > tree->n)
		value[1] = tree->n;
	if (tree->left)
		preorder_max_min(tree->left, value);
	if (tree->right)
		preorder_max_min(tree->right, value);
}

/**
 * binary_tree_is_bst - checks if a binary tree is bts
 * @tree: pointer to the node
 * Return: 1 if it is bts 0 otherwise
 **/
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int value[2], tmp1, tmp2;

	if (!tree)
		return (0);

	if (tree->left)
		tmp1 = (binary_tree_is_bst(tree->left));
	if (tree->right)
		tmp2 = (binary_tree_is_bst(tree->right));
	if (!tree->left && !tree->right)
		return (1);
	if (tree->left)
	{
		value[0] = tree->left->n;
		value[1] = value[0];
		preorder_max_min(tree->left, &value[0]);
		if (value[0] >= tree->n)
			return (0);
	}
	if (tree->right)
	{
		value[0] = tree->right->n;
		value[1] = value[0];
		preorder_max_min(tree->right, &value[0]);
		if (value[1] <= tree->n)
			return (0);
	}
	return (tmp1 && tmp2);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the node
 * Return: height of the tree from node
 **/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (0);
	right = binary_tree_height(tree->right) + 1;
	left = binary_tree_height(tree->left) + 1;
	if (left > right)
		return (left);
	else
		return (right);
}
