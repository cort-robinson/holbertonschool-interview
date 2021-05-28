#include "lists.h"

/**
 * is_palindrome - Checks if singly linked list is a palindrome.
 * @head: The head of the list.
 * Return: 1 if palindrome else 0.
 */

int is_palindrome(listint_t **head)
{
	listint_t *idx = *head;

	if (*head == NULL)
		return 1;

	while ((idx)->next != NULL)
	{
		putchar(idx->n);
		idx = idx->next;
	}

	return 0;
}
