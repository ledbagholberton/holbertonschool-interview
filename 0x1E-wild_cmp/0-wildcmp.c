#include "holberton.h"
#include <stdio.h>
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

	if (*s1 == '\0' || *s2 == '\0')
	{
		return (1);
	}
	else if (*s1 == *s2)
	{
		cmp = wildcmp(s1 + 1, s2 + 1);
	}
	else if (*s2 == '*')
	{
		if (*(s2 + 1) == *s1)
			cmp = wildcmp(s1 + 1, s2 + 2);
		else
			cmp = wildcmp(s1 + 1, s2);
	}
	else
		cmp = 0;
	return (cmp);
}
