#!/usr/bin/python3
"""
FUnction minOperations calculations
"""


def minOperations(n):
    """Function minOperations"""
    cost = 0
    if type(n) is not int:
        return 0
    if n < 2:
        return 0
    i = 2
    while (i <= n):
        while (n % i == 0):
            cost += i
            n = n/i
        i += 1
    return int(cost)
