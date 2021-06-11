#include "lists.h"

/**
 * check_cycle - Checks if a singly linked list has a cycle in it.
 * @list: Head of list to check.
 * Return: 0 if there's no cycle, 1 if cycle exists.
 */

int check_cycle(listint_t *list)
{
    listint_t *fast = list;
    listint_t *slow = list;

    while (fast && slow && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow)
            return (1);
    }

    return (0);
}
