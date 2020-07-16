#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * error - because we have only putchar and no printf
 * Return: Nothing
 */
void error(void)
{
	int a;
	char err[] = "Error\n";

	for (a = 0; a <= 5; a++)
		_putchar(err[a]);
	exit(98);
}

/**
 * main - check the code for Holberton School students.
 *
 *@argc: Counts arguments in argv
 *@argv: Strings after exe
 * Return: Al ways 0.
 */

int main(int argc, char *argv[])
{
	int i, j, tmp, l1, l2, l3, *a, *b;
	int *ans;

	if (argc < 3 || argv[1] == NULL || argv[2] == NULL)
		error();
	l1 = strlen(argv[1]);
	l2 = strlen(argv[2]);
	l3 = l1 + l2;
	ans = malloc(l3 * sizeof(int));
	a = malloc(l1 * sizeof(int));
	b = malloc(l2 * sizeof(int));

	for (i = l1 - 1, j = 0; i >= 0; i--, j++)
		{
		a[j] = argv[1][i] - '0';
		if (a[j] < 0 || a[j] > 9)
			error();
		}
	for (i = l2 - 1, j = 0; i >= 0; i--, j++)
		{
		b[j] = argv[2][i] - '0';
		if (b[j] < 0 || b[j] > 9)
			error();
		}
	for (i = 0; i < l2; i++)
		for (j = 0; j < l1; j++)
			ans[i + j] = ans[i + j] + b[i] * a[j];
	for (i = 0; i < l3; i++)
		{
		tmp = ans[i] / 10;
		ans[i] = ans[i] % 10;
		ans[i + 1] = ans[i + 1] + tmp;
		}
	for (i = l3 - 1; i >= 0; i--)
		if (i != l3 - 1 || ans[i] != 0)
			_putchar(ans[i] + '0');
	_putchar('\n');
	free(a);
	free(b);
	free(ans);
	return (0);
}
