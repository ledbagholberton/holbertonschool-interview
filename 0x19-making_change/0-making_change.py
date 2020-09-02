#!/usr/bin/python3
"""
Making change function
"""
import sys


def makeChange(coins, total):
    """ Function makeChange
    Given a pile of coins of different values, determine the fewest number
    of coins needed to meet a given amount total.
    If total is 0 or less, return 0
    If total cannot be met by any number of coins you have, return -1
    coins is a list of the values of the coins in your possession
    The value of a coin will always be an integer greater than 0
    You can assume infinite number of each denomination of coin in the list
    Return: fewest number of coins needed to meet total
    """
    m = len(coins)
    if total is 0:
        return 0
    table = [0 for i in range(total + 1)]
    table[0] = 0
    for i in range(1, total + 1):
        table[i] = sys.maxsize
    for i in range(1, total + 1):
        for j in range(m):
            if (coins[j] <= i):
                sub_res = table[i - coins[j]]
                if (sub_res != sys.maxsize and sub_res + 1 < table[i]):
                    table[i] = sub_res + 1
    if table[total] is not sys.maxsize:
        return table[total]
    else:
        return -1
