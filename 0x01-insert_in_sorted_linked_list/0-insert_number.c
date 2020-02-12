#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 * insert_node - insert a node
 * @head: pointer to head of list
 * @number: number to insert
 * Return: new node
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *current;

	current = *head;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = number;
	new->next = NULL;

	if (current == NULL)
	{
		new->next = NULL;
		*head = new;
	}
	else if (current->next == NULL && current->n > number)
	{
		new->next = current;
		*head = new;
	}
	else
	{
		while (current->next != NULL && current->next->n < number)
			current = current->next;
		if (current->n > number)
		{
			*head = new;
			new->next = current;
		}
		else
		{
			new->next = current->next;
			current->next = new;
		}
	}
	return (new);
}
