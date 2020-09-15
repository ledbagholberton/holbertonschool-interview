#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    int array2[] = {1001, 501, 201, 101, 91, 81, 71, 61, 51, 41, 31, 21, 11, 1};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    radix_sort(array, n);
    printf("\n");
    print_array(array, n);
    
    n = sizeof(array2) / sizeof(array2[0]);
    print_array(array2, n);
    printf("\n");
    radix_sort(array2, n);
    printf("\n");
    print_array(array2, n);
    return (0);
}
