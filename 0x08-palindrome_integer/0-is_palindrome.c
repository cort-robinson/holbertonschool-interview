#include "palindrome.h"

/**
 * is_palindrome - Checks if unsigned integer is a palindrome.
 * @n: Unsigned integer to check.
 * Return: 1 if palindrome, 0 otherwise.
 */

int is_palindrome(unsigned long n)
{
	unsigned long spartacus = n;
	unsigned long no_im_spartacus = 0;

	while (n > 0)
	{
		no_im_spartacus *= 10;
		no_im_spartacus += n % 10;
		n /= 10;
	}

	if (spartacus == no_im_spartacus)
		return (1);
	else
		return (0);
}
