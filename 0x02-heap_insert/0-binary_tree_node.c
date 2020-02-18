#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_node - function that creates a binary tree node
 * @value: Integer with the value in node created
 * @parent: is a pointer to the parent node of the node to create   
 * Return: pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *new;

    new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);
    
    new->n = value;
    new->parent = parent;
    return(new);
}
