#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge - merge two sorted arrays
 *
 * @array: array to merge
 * @size: size of array
 * @middle: middle index
 * @temp: temporary array
 */
void merge(int *array, size_t size, size_t middle, int *temp)
{
	size_t i = 0, j = middle, k = 0;

	printf("Merging...\n[left]: ");
	print_array(array, middle);
	printf("[right]: ");
	print_array(array + middle, size - middle);
	while (k < size)
	{
		if (j == size)
		{
			temp[k] = array[i];
			i++;
		}
		else if (i == middle || array[j] < array[i])
		{
			temp[k] = array[j];
			j++;
		}
		else
		{
			temp[k] = array[i];
			i++;
		}
		k++;
	}
	for (i = 0; i < size; i++)
		array[i] = temp[i];
	printf("[Done]: ");
	print_array(temp, size);
}

/**
 * merge_sort_rec - sorts an array of integers in ascending order using
 * the Merge sort algorithm recursively
 *
 * @array: array of integers
 * @size: size of the array
 * @temp: pointer to temp node
 */
void merge_sort_rec(int *array, size_t size, int *temp)
{
	if (size > 1)
	{
		merge_sort_rec(array, size / 2, temp);
		merge_sort_rec(array + size / 2, size - size / 2, temp);
		merge(array, size, size / 2, temp);
	}
}


/**
 * merge_sort - Sorts an array of integers in ascending
 * order using the merge sort algrithm and print using
 * print_array
 *
 * @array: Array of integers to be sorted
 * @size: Size of the array
 **/
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (!array || size < 2)
		return;
	temp = malloc(sizeof(int) * size);
	if (!temp)
		return;
	merge_sort_rec(array, size, temp);
	free(temp);
}
