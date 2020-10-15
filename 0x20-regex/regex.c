#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "regex.h"

/**
 * regex_match - verify regex in expressions
 * @str: is the string to scan
 * @pattern: is the regular expression
 * Return: 1 match / 0 Mo match
 */
int regex_match(char const *str, char const *pattern)
{
	if (strcmp(str, pattern) == 0)
		return (1);
	else
		return (0);
}