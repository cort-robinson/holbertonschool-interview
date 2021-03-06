#include "slide_line.h"

/**
 * slide_line - Slides and merges an array of integers.
 * @line: Pointer to array.
 * @size: Number of elements within @line.
 * @direction: SLIDE_LEFT or SLIDE_RIGHT.
 * Return: 1 on success, else 0.
 */

int slide_line(int *line, size_t size, int direction)
{
	if (direction != 0 && direction != 1)
		return (0);
	if (line == NULL || size < 1)
		return (0);
	if (direction == 0)
		slide_left(line, size);
	if (direction == 1)
		slide_right(line, size);
	return (1);
}

/**
* slide_right - move to the right
* @line: pointer to head of line
* @size: size of the int array
*/
void slide_right(int *line, size_t size)
{
	int i, pos = 0, max = size - 1, n = 0;

	for (i = max; i >= 0; i--)
	{
		if (line[i] == 0)
			pos++;
		if (line[i] > 0)
			n++;
		if (line[i] > 0 && pos > 0)
		{
			line[i + pos] = line[i];
			line[i] = 0;
			i = i + pos;
			pos = 0;
		}
	}
	pos = max;
	for (i = max; i > max - n; i--)
	{
		if (i > max - n + 1 && line[i] == line[i - 1])
		{
			line[pos] = line[i] + line[i - 1];
			line[i - 1] = 0;
			if (pos != i)
				line[i] = 0;
			pos--;
		}
		else if (line[i] > 0 && pos < max)
		{
			line[pos] = line[i];
			if (pos != i)
				line[i] = 0;
			pos--;
		}
		else if (line[i] > 0)
			pos--;
	}
}
/**
* slide_left - move to the left
* @line: pointer to head of line
* @size: size of the int array
*/
void slide_left(int *line, size_t size)
{
	int i, pos = 0, n = 0;

	for (i = 0; i < (int)size; i++)
	{
		if (line[i] == 0)
			pos++;
		if (line[i] > 0)
			n++;
		if (line[i] > 0 && pos > 0)
		{
			line[i - pos] = line[i];
			line[i] = 0;
			i = i - pos;
			pos = 0;
		}
	}
	pos = 0;
	for (i = 0; i < n; i++)
	{
		if (i < n - 1 && line[i] == line[i + 1])
		{
			line[pos] = line[i] + line[i + 1];
			line[i + 1] = 0;
			if (pos != i)
				line[i] = 0;
			pos++;
		}
		else if (line[i] > 0 && pos > 0)
		{
			line[pos] = line[i];
			if (pos != i)
				line[i] = 0;
			pos++;
		}
		else if (line[i] > 0)
			pos++;
	}
}
