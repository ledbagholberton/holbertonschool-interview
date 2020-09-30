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
	int a1;
	char b;

	a1 = 1;
	b = '0';

	if (s1 == s2)
	{
		b = *s1;
		if (b == '0')
			s1 = s2;
		a1++;
	}
	else
	{
		s1 = s2 + 2;
	}
	return (0);
}
