""" island perimeter
"""


def island_perimeter(grid):
    """function perimeter
    """
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


def move_grid(grid):
    """function move_grid
    """
    size_h = len(grid)
    size_w = len(grid[0])
    g1 = [0] * (size_w + 2)
    grid1 = [g1] * (size_h + 2)
    for i in range(size_h):
        for j in range(size_w):
            grid1[i+1][j+1] = grid[i][j]
    return grid1
