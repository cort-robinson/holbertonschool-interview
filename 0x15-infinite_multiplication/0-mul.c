#include "holberton.h"
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * main - multiplies two positive numbers
 *
 * @argc: argument count
 * @argv: arguments double pointer
 *
 * Return: result of multiplication
 */
int main(int argc, char **argv)
{
	int num1, num2, result;
	char results_s[4096];

	error_check(argc, argv);
	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);
	result = num1 * num2;
	itoa(result, results_s, 10);
	_puts(results_s);
	return (0);
}


/**
 * error_check - checks for errors
 *
 * @argc: argument count
 * @argv: arguments double pointer
 */
void error_check(int argc, char **argv)
{
	int i;

	if (argc != 3)
	{
		_puts("Error");
		exit(98);
	}
	for (i = 0; argv[1][i] != '\0'; i++)
	{
		if (!isdigit(argv[1][i]))
		{
			_puts("Error");
			exit(98);
		}
	}
	for (i = 0; argv[2][i] != '\0'; i++)
	{
		if (!isdigit(argv[2][i]))
		{
			_puts("Error");
			exit(98);
		}
	}
}


/**
 * _puts - prints a string to stdout
 *
 * @str: string to print
 */
void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);

	_putchar('\n');
}


/**
 * itoa - converts an integer to a string
 *
 * @value: integer to convert
 * @buffer: string to store result
 * @base: base of number to convert
 *
 * Return: string
 */
char *itoa(int value, char *buffer, int base)
{
	int i, n;

	if (base < 2 || base > 32)
		return (buffer);

	n = abs(value);

	i = 0;
	while (n)
	{
		int r = n % base;

		if (r >= 10)
			buffer[i++] = 65 + (r - 10);
		else
			buffer[i++] = 48 + r;

		n = n / base;
	}

	if (i == 0)
		buffer[i++] = '0';

	if (value < 0 && base == 10)
		buffer[i++] = '-';

	buffer[i] = '\0';
	reverse(buffer);

	return (buffer);
}


/**
 * reverse - reverses a string
 * @str: string to reverse
 * Return: reversed string
 */
void reverse(char *str)
{
	int i, j;
	char temp;

	for (i = 0, j = (int)_strlen(str) - 1; i < j; i++, j--)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}


/**
 * _strlen - returns the length of a string
 *
 * @s: string to check
 *
 * Return: length of string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;

	return (i);
}
