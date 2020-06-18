#include "sort.h"

/**
 * heap - 
 *
 *@array: list of integers
 *@max_size: max size for each iteration
 *@size: size of orginal list
 *@index: index
 */
void heap(int *array, size_t max_size, size_t size, size_t index)
{
  size_t max, right, left;
  int a;

  max = index;
  left = 2 * index + 1;
  right = 2 + index * 2;

  if (left < max_size && array[left] > array[max])
    max = left;

  if (right < max_size && array[right] > array[max])
    max = right;

  if (max != index)
    {
      a = array[index];
      array[index] = array[max];
      array[max] = a;
      print_array(array, size);
      heap(array, max_size, size, max);
    }
}

/**
 *heap_sort - sorts a list of integers in order ascenent using Heap Sort
 *
 *@array: list of integers to be sorted
 *@size: size of list
 */
void heap_sort(int *array, size_t size)
{
  int b, prim;

  if(!array || size < 1)
    return;
  for(b = (size / 2) - 1; b >= 0; b--)
    heap(array, size, size, b);
  for(b = size - 1; b > 0; b--)
    {
      prim = array[0];
      array[0] = array[b];
      array[b] = prim;
      print_array(array, size);
      heap(array, b, size, 0);
    }
}
