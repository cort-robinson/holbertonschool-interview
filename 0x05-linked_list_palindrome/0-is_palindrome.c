#include "lists.h"

/**
 * is_palindrome - Checks if singly linked list is a palindrome.
 * @head: The head of the list.
 * Return: 1 if palindrome else 0.
 */

int is_palindrome(listint_t **head)
{
	listint_t *fast = *head;
	listint_t *slow = *head;
	listint_t *first_half, *second_half;

	if (*head == NULL)
		return (1);

	/* fast traverses at twice the speed of slow */
	while (fast->next != NULL && fast->next->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}

	/* reverse second half of list for comparison with first half */
	second_half = reverse(slow->next);
	first_half = *head;

	/* compare first half of list with second half */
	while (second_half != NULL && first_half != NULL)
	{
		if (first_half->n != second_half->n)
			return (0);
		second_half = second_half->next;
		first_half = first_half->next;
	}
	return (1);
}

/**
 * reverse - Reverses linked list.
 * @head: Head of list to reverse.
 * Return: Reversed list head.
 */

listint_t *reverse(listint_t *head)
{
	/* new head when list is reversed */
	listint_t *new = NULL;
	listint_t *next;

	while (head != NULL)
	{
		/* store next node */
		next = head->next;
		/* set previous node as next node */
		head->next = new;
		/* set current head as previous node for next iteration */
		new = head;
		/* move head to next node to start next iteration */
		head = next;
	}
	return (new);
}
