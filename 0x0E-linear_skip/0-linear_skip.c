#include <stdlib.h>
#include <stdio.h>
#include "search.h"

/**
 * linear_skip - Search in linked list a value
 *
 * @list: Pointer to the linked list to be freed
 * @value: Value to search in linkedlist
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *node;

	if (!list)
	  return NULL;

	node = list->express;
	printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);

	while (node != NULL && node->n < value)
	  {
	    list = node;
	    node = node->express;
	    if (!node)
	      {
		node = list;
		while (node->next)
		  node = node->next;
		break;
	      }
	    printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);
	  }
	printf("Value found between indexes [%lu] and [%lu]\n", list->index, node->index);
	for (;list != NULL && node->n >= list->n; list = list->next)
	{
		printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
		if (list->n == value)
			return(list);
	}
	return NULL;
}
