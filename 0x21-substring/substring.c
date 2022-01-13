#include "substring.h"
#include <stdlib.h>
#include <string.h>

/**
 * find_substring - finds all possible substrings
 * containing a list of words within a given string
 *
 * @s: string to search in
 * @words: list of words to search for
 * @nb_words: number of words in the list
 * @n: address to store the number of words found
 *
 * s is the string to scan
 *
 * Return: allocated array of indexes in s where the
 * words are found or NULL if no words found
 **/

int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int *ret, i, word_len = 0;
	size_t str_len = 0;

	if (s == NULL || words == NULL || *words == NULL || nb_words == 0)
		return (NULL);

	*n = 0;

	for (i = 0; s[i] != '\0'; i++)
		str_len++;
	for (i = 0; words[0][i] != '\0'; i++)
		word_len++;

	ret = malloc(sizeof(int) * str_len);

	for (i = 0; *(s + i) != '\0'; i++)
	{
		if (is_substring(s + i, words, nb_words, word_len))
		{
			ret[*n] = i;
			(*n)++;
		}
	}

	if (*n == 0)
	{
		free(ret);
		return (NULL);
	}

	return (ret);
}

/**
 * is_substring - checks if a substring is a concatenation of words
 *
 * @s: substring to check
 * @words: array of words to check against
 * @nb_words: number of words in the array
 * @wordlen: length of each word in the array
 *
 * Return: true if the substring is a concatenation of words, false otherwise
 */
bool is_substring(char const *s, char const **word, int nb_words, int wordlen)
{
	int *checked, check_len = 0, i, j, in_array;
	bool match = true, found;

	checked = malloc(sizeof(int) * nb_words);

	for (i = 0; i < nb_words; i++)
		checked[i] = -1;

	for (i = 0; i < nb_words; i++)
	{
		found = false;
		for (j = 0; j < nb_words; j++)
		{
			in_array = check_array(checked, check_len, j);
			if (!in_array && check_word((s + (i * wordlen)), word[j]))
			{
				checked[check_len] = j;
				check_len++;
				found = true;
				break;
			}
		}
		if (!found)
		{
			match = false;
			break;
		}
	}
	free(checked);
	return (match);
}

/**
 * check_word - checks if word is in the substring
 *
 * @str: substring to check
 * @words: words to check against
 *
 * Return: true if word is in the substring, false otherwise
 */
bool check_word(char const *str, char const *words)
{
	int i = 0;

	for (i = 0; *(words + i) != '\0'; i++)
	{
		if (*(str + i) != *(words + i))
			return (false);
	}
	return (true);
}

/**
 * check_array - checks if an element is in the array
 *
 * @arr: array to check
 * @len: length of the array
 * @val: value to check
 *
 * Return: true if the value is in the array, false otherwise
 */
bool check_array(int *arr, int len, int val)
{
	int i = 0;

	for (i = 0; i < len; i++)
	{
		if (arr[i] == val)
			return (true);
	}
	return (false);
}
