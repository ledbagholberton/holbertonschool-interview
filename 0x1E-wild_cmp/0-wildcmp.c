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
	int cmp;
	if (*s1 == '\n' && *s2 == '\n')
	{
		cmp = 1;
	}
	else if (*s1 == *s2)
	{
		cmp = 1;
		wildcmp(s1 + 1, s2 + 1);
	}
	else if (*s2 == '*')
	{
		cmp = 1;
		wildcmp(s1 + 1, s2);
	}
	else
		cmp = 0;
	return (cmp);
}
