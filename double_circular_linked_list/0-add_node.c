#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * create_node - creates a new list node
 * @str: string to copy into the new node
 *
 * Return: address of the new node, or NULL on failure
 */
List *create_node(char *str)
{
	List *new;

	new = malloc(sizeof(List));
	if (!new)
		return (NULL);
	new->str = strdup(str);
	if (!new->str)
	{
		free(new);
		return (NULL);
	}
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

/**
 * add_node_end - adds a new node at the end of a double circular linked list
 * @list: the list to modify
 * @str: the string to copy into the new node
 *
 * Return: address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *new;
	List *last;

	new = create_node(str);
	if (!new)
		return (NULL);
	if (!*list)
	{
		new->next = new;
		new->prev = new;
		*list = new;
		return (new);
	}
	last = (*list)->prev;
	new->next = *list;
	new->prev = last;
	last->next = new;
	(*list)->prev = new;
	return (new);
}

/**
 * add_node_begin - adds a new node at the beginning of a double
 * circular linked list
 * @list: the list to modify
 * @str: the string to copy into the new node
 *
 * Return: address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *new;
	List *last;

	new = create_node(str);
	if (!new)
		return (NULL);
	if (!*list)
	{
		new->next = new;
		new->prev = new;
		*list = new;
		return (new);
	}
	last = (*list)->prev;
	new->next = *list;
	new->prev = last;
	last->next = new;
	(*list)->prev = new;
	*list = new;
	return (new);
}
