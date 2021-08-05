#include "search.h"

/**
 * struct skiplist_s - Singly linked list with an express lane
 *
 * @n: Integer
 * @index: Index of the node in the list
 * @next: Pointer to the next node
 * @express: Pointer to the next node in the express lane
 *
 * Description: singly linked list node structure with an express lane
 * for Holberton project
 */
// typedef struct skiplist_s
// {
// 	int n;
// 	size_t index;
// 	struct skiplist_s *next;
// 	struct skiplist_s *express;
// } skiplist_t;


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
	/*
	Write a function that searches for a value in a sorted skip list of integers.

	* Prototype : skiplist_t *linear_skip(skiplist_t *list, int value);
	* Where list is a pointer to the head of the skip list to search in
	* A node of the express lane is placed every index which is a multiple of the square root of the size of the list (see example below)
	* And value is the value to search for
	* You can assume that list will be sorted in ascending order
	* Your function must return a pointer on the first node where value is located
	* If value is not present in list or if head is NULL, your function must return NULL
	* Every time you compare a value in the list to the value you are searching, you have to print this value
	*/
	skiplist_t *node = list;
	skiplist_t *express = list;
	while (node != NULL) {
		if (node->n == value) {
			return node;
		}
		if (node->n < value) {
			node = node->next;
		} else {
			express = express->express;
			node = express;
		}
	}
	return NULL;
}
