#include "binary_trees.h"

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 * @root: Double pointer to root node of the Heap.
 * @value: Value to store in the node to be inserted.
 * Return: Pointer to the inserted node or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new, *parent;

	new = malloc(sizeof(heap_t));
	if (new == NULL)
		return (NULL);

	parent = *root;

	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;

	return (new);
}
