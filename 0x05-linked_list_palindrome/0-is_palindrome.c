#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * reverse - reverse a single linked list from pointer in ahead
 * @head_ref: pointer to start the reverse until NULL
 * Return Nothing
 */
void reverse(listint_t ** head_ref)
{
    listint_t *prev = NULL;
    listint_t *current = *head_ref;
    listint_t *next = NULL;
    while (current != NULL) 
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

/**
* middle - find the middle of linked list
* @head_ref: pointer to head
* Return pointer to middle list
*/
listint_t middle(listint_t **head)
{
    listint_t *fast = *head;
    listint_t *slow = *head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return (*slow);
}

/**
* comparation - compare two list from two pointers
* @head1: pointer to head list 1
* @head2: pointer to head list 2
* Return 1 if both list are equal / 0 other cases
*/
int comparison(listint_t *head1, listint_t *head2)
{
    while (head2 != NULL)
        {
            if (head1->n != head2->n)
                return (0);
            else
                {
                    head1 = head1->next;
                    head2 = head2->next;
                }
        }
    return (1);
}

/**
 * is_palindrome - checks if a singly list is palindrome
 * @head: pointer to head of list
 * Return: 0 is not palindrome / 1 if it is
 */
int is_palindrome(listint_t **head)
{
    listint_t *my_middle;

    if (*head == NULL)
        return (1);
    my_middle = middle(**head);
    reverse (my_middle);
    return (comparation(head, my_middle))
}
