#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers.
 *
 * @list: Pointer to the head of the skip list to search in.
 * @value: Value to search for.
 *
 * Return: Pointer to the first node containing the value, or NULL if the
 * value is not present in list or if head is NULL.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *node = list;
	skiplist_t *express = list;

	while (node != NULL)
	{
		if (node->n == value)
			return (node);
		if (node->n < value)
			node = node->next;
		else
		{
			express = express->express;
			node = express;
		}
	}
	return (NULL);
}
