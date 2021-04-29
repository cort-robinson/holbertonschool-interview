#include "lists.h"

/**
 * insert_node - Inserts a number into a sorted singly linked list.
 * @head: the head of the list.
 * @number: the number to insert.
 * Return: the address of the new node, or NULL if it failed.
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new, *current;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = number;

	current = *head;

	if (*head != NULL && current->n < number)
	{
		while (current->next != NULL && current->next->n < number)
			current = current->next;
		new->next = current->next;
		current->next = new;
	}
	else
	{
		new->next = current;
		*head = new;
	}

	return (new);
}
