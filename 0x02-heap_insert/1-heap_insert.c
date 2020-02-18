#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * heap_insert - function that inserts a value into a Max Binary Heap
 *
 * @root: double pointer to the root node of the Heap
 * @value: value in the node to be inserted
 *
 * Return:  a pointer to the inserted node, or NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
    size_t height;
    
    height = _height(*root);
    for (i = 0, height, i = i+1)
        {
            search
        }

}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the node
 * Return: height of the tree from #include "binary_trees.h"node
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

/**
 * _search - Found if there is a empty node
 *
 * @tree: Pointer to the node to search 
 *
 * Return: The pointer to parent node with empty
 */
heap_t *search(binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

    if (tree->right == NULL || tree->right == NULL)
        return(tree)
    

	height_l = tree->left ? 1 + _height(tree->left) : 0;
	height_r = tree->right ? 1 + _height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}