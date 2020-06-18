#ifndef _SORT_H
#define _SORT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void heap(int *array, size_t max_size, size_t size, size_t index);
void heap_sort(int *array, size_t size);
void print_array(int const *array, size_t size);

#endif
