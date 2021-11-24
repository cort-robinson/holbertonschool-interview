#include "holberton.h"
#include <stddef.h>

/**
 * wildcmp - compares two strings and returns 1 if they match, otherwise 0
 * s2 can contain the wildcard character '*'
 *
 * @s1: string 1
 * @s2: string 2
 *
 * Return: 1 if they match, otherwise 0
 **/

int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	if (*s1 == '\0' && *s2 == '*')
		return (wildcmp(s1, s2 + 1));
	if (*s1 == '*' && *s2 == '\0')
		return (0);
	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));
	if (*s2 == '*')
		return (wildcmp(s1, s2 + 1) || wildcmp(s1 + 1, s2));
	return (0);
}
