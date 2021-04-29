#include "lists.h"

/**
 * insert_node - Inserts a number into a sorted singly linked list.
 * @head: the head of the list.
 * @number: the number to insert.
 * Return: the address of the new node, or NULL if it failed.
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *next;
	listint_t *index;

	if (*head == NULL || head == NULL)
		return (NULL);

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = number;

	index = *head;

	while (index->next != NULL && index->next->n < number)
		index = index->next;

	next = index->next;
	index->next = new;
	new->next = next;

	return (new);
}
