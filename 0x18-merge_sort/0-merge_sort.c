#include "sort.h"
#include <stdlib.h>

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
	size_t i, j, k;

	if (size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	for (i = 0; i < size; i++)
		temp[i] = array[i];

	for (i = 1; i < size; i *= 2)
	{
		for (j = 0; j < size - i; j += i * 2)
		{
			for (k = 0; k < i; k++)
			{
				if (temp[j + k] > temp[j + i + k])
				{
					array[j + k] = temp[j + k];
					array[j + i + k] = temp[j + i + k];
				}
				else
				{
					array[j + k] = temp[j + i + k];
					array[j + i + k] = temp[j + k];
				}
			}
		}
	}
	free(temp);
	print_array(array, size);
}
