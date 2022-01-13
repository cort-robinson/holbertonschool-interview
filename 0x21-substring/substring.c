#include "substring.h"
#include <stdlib.h>
#include <string.h>

/**
 * find_substring - finds all possible substrings containing a list of words within a given string
 *
 * @s: string to search in
 * @words: list of words to search for
 * @nb_words: number of words in the list
 * @n: address to store the number of words found
 *
 * s is the string to scan
words is the array of words all substrings must be a concatenation arrangement of
nb_words is the number of elements in the array words
n holds the address at which to store the number of elements in the returned array.
Your function must return an allocated array, storing each index in s, at which a substring was found. If no solution is found, NULL can be returned
All words in the array words are the same length
A valid substring of s is the concatenation of each word in words exactly once and without any intervening characters
 *
 * Return: allocated array of indexes in s where the words are found or NULL if no words found
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
 * match - checks if a substring is a concatenation of words
 *
 * @s: substring to check
 * @words: array of words to check against
 * @nb_words: number of words in the array
 * @word_len: length of each word in the array
 *
 * Return: true if the substring is a concatenation of words, false otherwise
 */
bool is_substring(char const *s, char const **words, int nb_words, int word_len)
{
    int i, j;

    for (i = 0; i < nb_words; i++)
    {
        for (j = 0; j < word_len; j++)
        {
            if (s[j] != words[i][j])
                break;
        }
        if (j == word_len)
            return (true);
    }
    return (false);
}
