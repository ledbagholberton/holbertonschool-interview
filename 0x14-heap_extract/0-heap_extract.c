#include "binary_trees.h"
/**
 * bt_preorder - ensure the righ location in childs
 * @tree: pointer to tree
 * @node: pointer to node
 * @h: height of tree
 * @level: position of node in the tree
 * Return: Void function
 **/
void bt_preorder(heap_t *tree, heap_t **node, size_t h, size_t level)
{
	if (!tree)
		return;
	if (level == h)
		*node = tree;
	level = level + 1;
	if (tree->left)
		bt_preorder(tree->left, node, h, level);
	if (tree->right)
		bt_preorder(tree->right, node, h, level);
}
/**
 * bt_height - return the height of tree
 * @tree: pointer to tree
 *
 * Return: Void function
 **/
size_t bt_height(heap_t *tree)
{
	size_t right, left;

	if ((!tree) || (!tree->left && !tree->right))
		return (0);
	right = bt_height(tree->right) + 1;
	left = bt_height(tree->left) + 1;
	if (left > right)
		return (left);
	return (right);
}
/**
 * heap_extract - extracts the root node from a Max Binary Heap
 * @root: pointer to the heap root
 * Return: value of extracted node
 **/
int heap_extract(heap_t **root)
{
	int value, value_aux;
	size_t level = 0;
	heap_t *aux, *node;

	if (!root || !*root)
		return (0);
	aux = *root;
	value = aux->n;
	if (!aux->left && !aux->right)
	{
		*root = NULL;
		free(aux);
		return (value);
	}
	bt_preorder(aux, &node, bt_height(aux), level);
	while (aux->left || aux->right)
	{
		if (!aux->right || aux->left->n > aux->right->n)
		{
			value_aux = aux->n;
			aux->n = aux->left->n;
			aux->left->n = value_aux;
			aux = aux->left;
		}
		else if (!aux->left || aux->left->n < aux->right->n)
		{
			value_aux = aux->n;
			aux->n = aux->right->n;
			aux->right->n = value_aux;
			aux = aux->right;
		}
	}
	aux->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	return (value);
}
