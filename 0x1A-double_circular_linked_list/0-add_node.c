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
List *new, *tmp;

if (!list || !str)
	return (NULL);
new = malloc(sizeof(List));
if (!new)
	return (NULL);
new->str = strdup(str);
if (!new->str)
	{
	free(new);
	return (NULL);
	}
if (*list == NULL)
	{
	new->next = new;
	new->prev = new;
	*list = new;
	return (new);
	}
tmp = (*list)->prev;
tmp->next = new;
new->next = *list;
new->prev = tmp;
(*list)->prev = new;
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
List *new, *tmp;

if (!list || !str)
	return (NULL);
new = malloc(sizeof(List));
if (!new)
	return (NULL);
new->str = strdup(str);
if (!new->str)
	{
	free(new);
	return (NULL);
	}
if (*list == NULL)
	{
	new->next = new;
	new->prev = new;
	*list = new;
	return (new);
	}
tmp = (*list)->prev;
new->next = (*list);
new->prev = tmp;
(*list)->prev = new;
tmp->next = new;
*list = new;
return (new);
}
