#include "binary_trees.h"
/**
 * sorted_array_to_avl - Function  builds an AVL tree from an array
 *
 * @array: matrix i
 * @size: matrix j
 * Return: Pointer to root
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *head;

	if (!array)
		return (NULL);
	if (size < 1)
		return (NULL);
	head = create_avl(NULL, array, 0, size - 1);
	return (head);
}

/**
 * create_avl - Function create_avl tree from array
 *
 * @parent: pointer to parent
 * @array: pointer to arrat of integers
 * @ini: index to start of array
 * @end: index to end of array
 * Return: Pointer to root
 */
avl_t *create_avl(avl_t *parent, int *array, size_t ini, size_t end)
{
	avl_t *node;
	size_t pos;

	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);
	pos = (ini + end) / 2;
	node->n = array[pos];
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	if (pos != ini)
		node->left = create_avl(node, array, ini, pos - 1);
	if (pos != end)
		node->right = create_avl(node, array, pos + 1, end);
	return (node);
}
