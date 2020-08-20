#include "sort.h"
/**
 * merge_sort - Sort merge method
 *@array: array unsorted
 *@size: size
 * Return: Non return
 */
void merge_sort(int *array, size_t size)
{
	int mid_der[500], mid_izq[500];
	size_t i, j, new_size;

	if (!array)
		return;
	if (size <= 1)
		return;
	new_size = size / 2;
	for (i = 0; i < new_size; i++)
		mid_izq[i] = array[i];
	for (j = new_size; j < size; j++)
		mid_der[j - new_size] = array[j];
	merge_sort(mid_izq, new_size);
	merge_sort(mid_der, size - new_size);
	uni(array, mid_izq, mid_der, size);
}
/**
 * union - Union arrays
 *@array: array unsorted
 *@mid_izq: pointer to array left
 *@mide_left: pointer to array right
 *@size: size
 * Return: Non return
 */
void uni(int *array, int *left, int *right, size_t size)
{
	size_t size_l, size_r, i = 0, j = 0, k = 0;
	
	size_l = size / 2;
	size_r = size - size_l;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, size_l);
	printf("[right]: ");
	print_array(right, size_r);
	while (i < size_l && j < size_r)
	{
		if (left[i] < right[j])
			array[k++] = left[i++];
		else
		{
			array[k++] = right[j++];
		}
	}
	while (i < size_l)
	{
		array[k++] = left[i++];
	}
	while (j < size_r)
	{
		array[k++] = right[j++];
	}
	printf("[Done]: ");
	print_array(array, size);
}
