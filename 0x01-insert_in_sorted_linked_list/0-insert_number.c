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
listint_t *past;

current = *head;
past = *head;
new = malloc(sizeof(listint_t));
if (new == NULL)
   return (NULL);
new->n = number;
new->next = NULL;
if (*head == NULL)
  *head = new;
else if (current->next == NULL && current->n > number)
  {
    new->next = current;
    *head = new;
  }
else
  {
    while (current->n < number || current->next != NULL)
      {
	past = current;
	current = current->next;
	printf("En el loop %i\n", current->n);
      }
    past->next = new;
    if (current != NULL)
      new->next = current;
  }
 return (new);
}
