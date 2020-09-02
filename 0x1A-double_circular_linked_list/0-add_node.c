#include <stdio.h>
#include <stdlib.h>
#include "list.h"
/**
 * add_node_end - add node at end of DLL
 *
 * @list: points to list
 * @str: info en structure
 *
 * Return: Pointer to new node or NULL
 */
List *add_node_end(List **list, char *str)
{
List *new;

if (!list || !str)
	return (NULL);
new = malloc(sizeof(List));
(*list)->prev->next = new;
(*list)->prev = new;
new->next = *list;
new->prev->next = new;
new->str = str;
return (new);
}

/**
 * add_node_begin - add node at begin of DLL
 * @list: points to list
 * @str: info en structure
 *
 * Return: Pointer to new
 */
List *add_node_begin(List **list, char *str)
{
List *new;

if (!list || !str)
	return (NULL);
new = malloc(sizeof(List));
new->prev = (*list)->prev;
new->prev->next = new;
new->next->prev = new;
(*list) = new;
(*list)->str = str;
return (new);
}
