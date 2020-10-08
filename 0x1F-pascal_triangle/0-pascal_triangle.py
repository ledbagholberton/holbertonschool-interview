#!/usr/bin/python3
"""
Pascal triangle
"""


def pascal_triangle(n):
    """ Pascal triangle
    """
    if (n <= 0):
        return []
    a = [[1]]
    for i in range(1, n):
        x = [1] * (i + 1)
        a.append(x)
        for j in range(1, i):
            a[i][j] = a[i-1][j-1]
            a[i][j] += a[i-1][j]
    return(a)
