#include <stdlib.h>
#include <stdio.h>

#include "sandpiles.h"

/**
 * sandpiles_sum - Function sum sandpiles
 *
 * @grid1: sandpile 1
 * @grid2: sandpile2
 *
 * Return: None
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, a;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
		}
	}
	a = is_not_stable(grid1);
	while (a == 1)
	{
		toople(grid1);
		a = is_not_stable(grid1);
	}
}

/**
 * is_not_stable - Function determine sandpile is stable
 *
 * @grid1: sandpile 1
 *
 * Return: 1 if not stable
 */
int is_not_stable(int grid1[3][3])
{
	int i, j;
	int a = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			a = 1;
		}
	}
	return (a);
}

/**
 * toople - Function toople for sandpiles
 *
 * @grid1: sandpile 1
 *
 * Return: None
 */
void toople(int grid1[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				grid1[i][j] = grid1[i][j] - 4;
				if (i - 1 >= 0)
					grid1[i - 1][j] = grid1[i - 1][j] + 1;
				if (i + 1 < 3)
					grid1[i + 1][j] = grid1[i + 1][j] + 1;
				if (j - 1 >= 0)
					grid1[i][j - 1] = grid1[i][j - 1] + 1;
				if (j + 1 < 3)
					grid1[i][j + 1] = grid1[i][j + 1] + 1;
			}
		}
	}
}
