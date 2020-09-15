#include "sort.h"
#include <stdio.h>

/**
 * radix_sort - implement radix sort
 * @array: pointer to array to be sorted
 * @size: size of array
 * Return: No return
 **/
void radix_sort(int *array, size_t size)
{
	size_t i, k;
	int ix, bucket[10][10], b_cnt[10], j, r, NOP = 0, divisor = 1, lar, pass;

	if (size < 2)
		return;
	lar = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > lar)
			lar = array[i];
	}
	while (lar > 0)
	{
		NOP++;
		lar /= 10;
	}
	for (pass = 0; pass < NOP; pass++)
	{
		for (i = 0; i < size; i++)
		{
			b_cnt[i] = 0;
		}
		for (i = 0; i < size; i++)
		{
			r = (array[i] / divisor) % 10;
			bucket[r][b_cnt[r]] = array[i];
			b_cnt[r] += 1;
		}
		ix = 0;
		for (k = 0; k < size - 2; k++)
		{
			for (j = 0; j < b_cnt[k]; j++)
			{
				array[ix] = bucket[k][j];
				ix++;
			}
		}
		divisor *= 10;
		print_array(array, size);
	}
}
