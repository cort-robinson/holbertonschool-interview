#ifndef SORT_H
#define SORT_H

#include <stddef.h>

void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
void sift_down(int *array, int node_value, int root, int end);

#endif /* SORT_H */
