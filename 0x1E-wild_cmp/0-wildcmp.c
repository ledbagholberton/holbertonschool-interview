#include "holberton.h"
/**
 * wildcmp - Compares two strings with wildcards
 *
 * @s1: Pointer to string 1
 * @s2: Pointer to string 2
 * Return: Integer 1 if strings are equal / 0 otherwise
 */

int wildcmp(char *s1, char *s2)
{
	int cmp = 0;

	if (*s1 == *s2 && *s1 != '\n')
	{
		cmp = 1;
		wildcmp(s1 + 1, s2 + 1);
	}
	else
		cmp = 0;
	return (cmp);
}
