#include "binary_trees.h"
/**
 * sorted_array_to_avl - Function  builds an AVL tree from an array
 *
 * @array: matrix i
 * @size: matrix j
 * Return: Pointer to root
 */
int heap_extract(heap_t **root)
{
	avl_t *head;

	if (!array)
		return (NULL);
	if (size < 1)
		return (NULL);
	head = create_avl(NULL, array, 0, size - 1);
	return (head);
}