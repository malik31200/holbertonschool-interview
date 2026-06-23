#include "lists.h"
#include <stdlib.h>

/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: double pointer to the haed of the list
 * @number: number to insert in sorted order
 *
 * Description: The function creates a new node and inserts it into
 * an already sorted linked list while keeping the order.
 *
 * Return: address of the new node -, or NULL if it fails
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *current;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = number;

	/* insert in head */
	if (*head == NULL || (*head)->n >= number)
	{
		new->next = *head;
		*head = new;
		return (new);
	}

	current = *head;

	/* find the position */
	while (current->next != NULL && current->next->n < number)
		current = current->next;

	/* insertion */
	new->next = current->next;
	current->next = new;

	return (new);
}
