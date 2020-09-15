#!/usr/bin/python3
"""
Function island parameter
"""


def insert_bound(grid):
    """
    insert rows and cols
    """
    size_w = len(grid[0]) + 1
    for i in grid:
        i.insert(0, 0)
        i.insert(size_w, 0)
    g_i = [0] * len(grid[0])
    grid.insert(0, g_i)
    grid.insert(len(grid) + 1, g_i)


def island_perimeter(grid):
    """function perimeter
    """
    insert_bound(grid)
    size_h = len(grid)
    size_w = len(grid[0])
    b = 0
    for i in range(size_h):
        for j in range(size_w):
            a = 0
            if grid[i][j] is 1:
                a = 4
                if grid[i+1][j] is not 0:
                    a = a - 1
                if grid[i-1][j] is not 0:
                    a = a - 1
                if grid[i][j+1] is not 0:
                    a = a - 1
                if grid[i][j-1] is not 0:
                    a = a - 1
            b += a
    return b
