#include "search_algos.h"
#include <stdio.h>

/**
 * search - Search for a value in a sorted array of integers
 *
 * @array: Array of integers
 * @size: Size of array
 * @value: Value to search for
 * @start: Starting index
 * @end: Ending index
 * Return: Index of value or -1 if not found
 */
int search(int *array, size_t size, int value, int start, int end)
{
	int i, mid;

	if (array == NULL || size == 0)
		return (-1);

	printf("Searching in array: ");
	for (i = start; i <= end; i++)
	{
		if (i == end)
			printf("%d\n", array[i]);
		else
			printf("%d, ", array[i]);
	}
	if (start > end)
		return (-1);
	mid = (start + end) / 2;
	if (array[mid] == value)
		return (mid);
	if (array[mid] > value)
		return (search(array, size, value, start, mid - 1));
	else
		return (search(array, size, value, mid + 1, end));
}

/**
 * advanced_binary - Binary search algorithm
 *
 * @array: Pointer to array to search
 * @size: Number of elements in array
 * @value: value to search for
 * Return: Index of value if found, -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	return (search(array, size, value, 0, size - 1));
}
