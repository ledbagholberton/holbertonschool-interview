#include "lists.h"

/**
 * check_cycle - check loop in linked lists.
 *@list: head of linked list
 *
 * Return: 1 if loop / 0 otherwise
 */

int check_cycle(listint_t *list)
{
	listint_t *aux, *aux2;

	aux = list;
	aux2 = list;

	if (list == NULL || aux -> next == NULL || aux -> next -> next == NULL)
		return(0);
	do {
		aux = aux->next;
		aux2 = aux2->next->next;
		if (aux == aux2)
			return (1);
	} while (aux != NULL && aux2 != NULL && aux2->next != NULL);
	return (0);
}
