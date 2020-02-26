#!/usr/bin/python3
"""
FUnction minOperations calculations
"""


def minOperations(n):
    """Function minOperations"""
    cost = 0
    if type(n) is not int:
        return 0
    if n <= 0 or type(n) is not int:
        return 0
    while (n > 0):
        if (n % 2) != 0:
            cost = cost + 1
            n = n - 1
        else:
            temp = n / 2
            if (temp > 2):
                cost = cost + 2
            else:
                cost = cost + temp
            n = n / 2
    return int(cost)
