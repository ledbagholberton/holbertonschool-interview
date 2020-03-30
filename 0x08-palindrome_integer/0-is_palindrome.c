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
    printf("%i is first and %i is last\n", fs, ls);
    if (sz > 2)
    {
        if (fs != ls)
            return(0);
        else
        {
            pow = power(10, sz - 1);
            n1 = n - (fs * pow);
            n2 = (n1 - ls) / 10;
            printf("nuevo n es %lu\n", n2);
            is_palindrome(n2);
        }
    }
    else if(sz == 2)
    {
        printf("Len es menor que 3. Len = %i\n", sz);
        if (fs != ls)
            return(0);
        else
            return(1);
    }
    return(1);
}

unsigned long power(int base, int exponent)
{
    int result=1, a;

    for (a = exponent; a > 0; a = a - 1)
    {
        result = result * base;
    }
    return result;
}

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

unsigned long last(unsigned long n)
{
    unsigned long last;

    last = n % 10;
    return (last);
}

unsigned long first(unsigned long n)
{
    unsigned long first;

    first = n;
    while(first >= 10)
        first = first / 10;
    return (first);
}
