#include <stdlib.h>
#include <stdio.h>
#include "search_algos.h"

/**
 * advanced_binary - Search algorithm
 *
 * @array: pointer to the first element of the array to search
 * @size: number of elements in array
 * @value: value to search
 * Return: Index where value is
**/
int advanced_binary(int *array, size_t size, int value)
{
	size_t med_size, a, b = 0;
	int pos;

	if (array == NULL)
		return (-1);
	if (size == 0)
		return (-1);
	printf("Searching in array: ");
	for (a = 0; a < size - 1; a++)
		printf("%d, ", array[a]);
	printf("%d\n", array[a]);
	if (array[0] != value && size == 1)
		return (-1);
	med_size = (size - 1) / 2;
	if (array[med_size] == value)
		if (med_size == 0 || array[med_size - 1] < value)
			return ((int)med_size);
	if (array[med_size] < value)
	{
		b = b + med_size + 1;
		array = array + med_size + 1;
		if (size % 2 == 0)
			med_size = med_size - 1;
	}
	med_size = med_size + 1;
	pos = advanced_binary(array, med_size, value);
	if (pos == -1)
		return (-1);
	return (pos + b);
}
