#ifndef SUBSTRING_H
#define SUBSTRING_H

#include <stdbool.h>

int *find_substring(char const *s, char const **words, int nb_words, int *n);
bool is_substring(char const *s, char const **words, int nb_words, int word_len);
bool check_word(char const *str, char const *words);
bool check_array(int *arr, int len, int val);

#endif /* SUBSTRING_H */
