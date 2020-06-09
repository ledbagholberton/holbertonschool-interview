#!/usr/bin/python3
"""
Funtion rain
"""


def rain(walls):
    """Function rain"""
    n = len(walls)
    if n == 0:
        return 0
    else:
        max_ = 0
        left = [0] * n
        right = [0] * n
        left[0] = walls[0]
        for i in range(1, n):
            left[i] = max(left[i-1], walls[i])
        right[n-1] = walls[n-1]
        for i in range(n - 2, -1, -1):
            right[i] = max(right[i+1], walls[i])
        vol = 0
        for i in range(0, n):
            a = left[i]
            b = right[i]
            vol = vol + min(a, b) - walls[i]
    return (vol)
