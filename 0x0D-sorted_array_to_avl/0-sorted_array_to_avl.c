#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * sorted_array_to_avl - Builds an AVL tree from an array
 *
 * @array: A pointer to the first element of the array to be converted
 * @size: The number of elements in the arrray
 *
 * Return: A pointer to the root node of the created AVL tree,
 * or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	return (create_avl(array, 0, size - 1, NULL));
}


/**
 * create_avl - Creates an AVL tree from a sorted array
 *
 * @array: A pointer to the first element of the array to be converted
 * @start: The index of the first element in the array to be converted
 * @end: The index of the last element in the array to be converted
 * @prev: A pointer to the previous root node for recursion
 *
 * Return: A pointer to the root node of the created AVL tree,
 * or NULL on failure
 */
avl_t *create_avl(int *array, int start, int end, avl_t *prev)
{
	int mid;
	avl_t *root;

	if (start > end)
		return (NULL);

	mid = start + (end - start) / 2;
	root = create_node(array[mid]);
	if (!root)
		return (NULL);
	root->parent = prev;
	root->left = create_avl(array, start, mid - 1, root);
	root->right = create_avl(array, mid + 1, end, root);
	return (root);
}


/**
 * create_node - Creates a node for an AVL tree
 *
 * @n: The data for the node to be created
 *
 * Return: A pointer to the created node, or NULL on failure
 */
avl_t *create_node(int n)
{
	avl_t *node = (avl_t *)malloc(sizeof(avl_t));

	if (!node)
		return (NULL);

	node->n = n;
	node->parent = NULL;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
