#include "sort.h"

void sift_down(int *array, int node_value, int root, int end) {
    int left_child = 2 * root + 1;

    while (left_child <= end) {
        if (left_child < end) {
            if (array[left_child + 1] > array[left_child]) {
                left_child++;
            }
        }
        if (node_value >= array[left_child])
            break;
        else {
            array[root] = array[left_child];
            root = left_child;
            left_child = 2 * root + 1;
        }
        array[root] = node_value;
    }
}

/**
 * heap_sort: Sorts an array of integers in ascending
 * order using the sift down heap sort algorithm.
 * Array must be printed each time two elements are swapped.
 *
 * @array: An pointer to an array of integers.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size) {
    for (int i = size / 2; i >= 0; i--) {
        sift_down(array, array[i], i, size);
    }

    for (int last_node = size - 1; last_node > 0; last_node--) {
        int last_node_value = array[last_node];
        array[last_node] = array[0];
        array[0] = last_node_value;
        print_array(array, size);
        sift_down(array, last_node_value, 0, last_node - 1);
    }
}
