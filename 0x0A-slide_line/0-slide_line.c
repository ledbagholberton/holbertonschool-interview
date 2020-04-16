#include <stdlib.h>
#include <stdio.h>
#include "slide_line.h"

/**
 * slide_line - Function 2048
 *
 * @line: pointer to array of integers
 * @size: size of array
 * @direction: direction to sum
 * Return: 1 or 0
**/
int slide_line(int *line, size_t size, int direction)
{
	int array1[32];
	size_t i, j = 0;

	for (i = 0; i < size; i++)
	array1[i] = 1;
	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
	return (0);
	if (direction == SLIDE_LEFT)
	left_array1(array1, line, size);
	else
	right_array1(array1, line, size);
	for (i = 0; i < size; i++)
	array1[i] = array1[i] * line[i];
	for (i = 0; i < size; i++)
	line[i] = 0;
	if (direction == SLIDE_LEFT)
	{
		for (i = 0; i < size; i++)
		if (array1[i] != 0)
			{
			line[j] = array1[i];
			j = j + 1;
			}
	}
	else
	{
		j = size;
		for (i = size; (int) i >= 0; i--)
		if (array1[i] != 0)
			{
			line[j] = array1[i];
			j = j - 1;
			}
	}
	return (1);
}

/**
 * left_array1 - Generate an vector answer if direction Left
 * @array1: Pointer to the array of integer to analyze
 * @size: Number of elements in @array
 * @line: Origin vector
 */
void left_array1(int *array1, int *line, size_t size)
{
	size_t i;
	int flag = 0, pos;

	for (i = 0; i < size; i++)
	{
		if (line[i] == 0)
		{
			array1[i] = 1;
		}
		else
		{
			if (flag == 0)
			{
				pos = i;
				flag = 1;
				array1[i] = 1;
			}
			else
			{
				if (line[i] == line[pos])
				{
					array1[pos] = 2;
					array1[i] = 0;
					flag = 0;
				}
				else
				{
					array1[i] = 1;
					pos = i;
				}
			}
		}
	}
}

/**
 * right_array1 - Generate a vactor answer if driectio Right
 * @array1: Pointer to the array of integer to analyze
 * @size: Number of elements in @array
 * @line: Origin vector
 */
void right_array1(int *array1, int *line, size_t size)
{
	size_t i;
	int flag = 0, pos;

	for (i = size; (int) i >= 0; i--)
	{
		if (line[i] == 0)
		{
			array1[i] = 1;
		}
		else
		{
			if (flag == 0)
			{
				pos = i;
				flag = 1;
				array1[i] = 1;
			}
			else
			{
				if (line[i] == line[pos])
				{
					array1[pos] = 2;
					array1[i] = 0;
					flag = 0;
				}
				else
				{
					array1[i] = 1;
					pos = i;
				}
			}
		}
	}
}
