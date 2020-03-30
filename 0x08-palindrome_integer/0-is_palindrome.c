#include "palindrome.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * is_palindrome - FUnction to determine
 *
 * @n: Number
 *
 * Return: 1 or 0
 */
int is_palindrome(unsigned long n)
{
int fs, ls, sz;
unsigned long pow, n1, n2;

fs = first(n);
ls = last(n);
sz = len(n);
if (sz > 2)
{
    if (fs != ls)
        return (0);
    else
        {
            pow = power(10, sz - 1);
            n1 = n - (fs *pow);
            n2 = (n1 - ls) / 10;
            return (is_palindrome(n2));
        }
}
else if (sz == 2)
    if (fs != ls)
        return (0);
    return (1);
}

/**
 * power - FUnction power
 *
 * @base: Number
 * @exponent: Number
 * Return: base ^ exponent
 */
unsigned long power(int base, int exponent)
{
    int a;
    unsigned long result = 1;

    for (a = exponent; a > 0; a = a - 1)
        result = result * base;
    return (result);
}

/**
 * len - size of number
 *
 * @n: Number
 *
 * Return: size of number
 */
int len(unsigned long n)
{
    int count = 0;

    while (n != 0)
    {
        n = n / 10;
        count = count + 1;
    }
    return (count);
}

/**
 * last - last digit in n
 *
 * @n: Number
 *
 * Return: last digit
 */
unsigned long last(unsigned long n)
{
    unsigned long last;

    last = n % 10;
    return (last);
}

/**
 * first - first digit in n
 *
 * @n: Number
 *
 * Return: first digit
 */
unsigned long first(unsigned long n)
{
    unsigned long first;

    first = n;
    while (first >= 10)
        first = first / 10;
    return (first);
}
