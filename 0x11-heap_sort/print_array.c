#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * print_array - Prints out an array of integer, followed by a new line
 * 
 * @array: Pointer to the array of integer to be printed
 * @size: Number of elements in @array
 */
void print_array(int const *array, size_t size)
{
    size_t i;

    printf("Line: ");
    for (i = 0; i < size; i++)
	printf("%s%d", i > 0 ? ", " : "", array[i]);
    printf("\n");
}
