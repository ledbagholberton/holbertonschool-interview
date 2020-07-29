#include "lists.h"

/**
 * find_listint_loop - check the code for Holberton School students.
 *@head: head od linked list
 *
 * Return: Node of loops.
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *aux1, *aux2;

	aux1 = head;
	aux2 = head;
	while (aux2 != NULL && aux2->next != NULL)
	{
		aux1 = aux1->next;
		aux2 = aux2->next->next;
		if (aux1 == aux2)
		{
			aux2 = head;
			while (aux1 != aux2)
			{
				aux1 = aux1->next;
				aux2 = aux2->next;
			}
			return (aux1);
		}
	}
	return (NULL);
}
