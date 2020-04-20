#include <stdlib.h>
#include <stdio.h>
#include "menger.h"
#include <math.h>

/**
 * masked - Function in charge to determine gap or not
 *
 * @i: matrix i
 * @j: matrix j
 * Return: None
 */
int masked(int i, int j)
{
	while (i > 0 || j > 0)
	{
		if ((i % 3 == 1) && j % 3 == 1)
			return (0);
		i = i / 3;
		j = j / 3;
	}
return (1);
}

/**
 * back - Function for edge cases
 *
 * @level: level of deep in Merge Sponge
 *
 * Return: return 0 if level is not -1
 */
int back(int level)
{
	if (level == -1)
		printf("#\n");
	return (0);
}

/**
 * menger - Function menger
 *
 * @level: level of deep in Merge Sponge
 *
 * Return: None
 */
void menger(int level)
{
	int count, i, j;

	if (level == 0)
		printf("#\n");
	else
		back(0);

	count = pow(3, level);
	for (i = 0; i < count && level > 0; i++)
	{
		for (j = 0; j < count; j++)
			if (masked(i, j) == 1)
				printf("%c", '#');
			else
				printf("%c", ' ');
		printf("\n");
	}
}
