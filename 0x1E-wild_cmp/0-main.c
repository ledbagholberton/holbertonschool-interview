#include "holberton.h"
#include <stdio.h>
/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */

int main(void)
{
    int r;

    r = wildcmp("main.c", "*.c");
    printf("main.c, *.c \n");
    printf("%d\n", r);
    r = wildcmp("main.c", "m*a*i*n*.*c*");
    printf("main.c, m*a*i*n*.*c* \n");
    printf("%d\n", r);
    r = wildcmp("main.c", "main.c");
    printf("main.c, main.c \n");
    printf("%d\n", r);
    r = wildcmp("main.c", "m*c");
    printf("main.c, m*c \n");
    printf("%d\n", r);
    r = wildcmp("main.c", "ma********************************c");
    printf("main.c, ma********************************c \n");
    printf("%d\n", r);
    r = wildcmp("main.c", "*");
    printf("main.c, * \n");
    printf("%d\n", r);
    r = wildcmp("main.c", "***");
    printf("main.c, *** \n");
    printf("%d\n", r);
    r = wildcmp("main.c", "m.*c");
    printf("main.c, m.*c \n");
    printf("%d\n", r);
    r = wildcmp("main.c", "**.*c");
    printf("main.c, **.*c \n");
    printf("%d\n", r);
    r = wildcmp("main-main.c", "ma*in.c");
    printf("main-main.c, ma*in.c \n");
    printf("%d\n", r);
    r = wildcmp("main", "main*d");
    printf("main, main*d \n");
    printf("%d\n", r);
    r = wildcmp("abc", "*b");
    printf("abc, *b \n");
    printf("%d\n", r);
    return (0);
}
