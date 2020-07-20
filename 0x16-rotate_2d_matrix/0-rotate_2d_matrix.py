#!/usr/bin/python3
"""
Rotate 2D Matrix
"""


def rotate_2d_matrix(matrix):
    """Rotate 2D Matrix"""
    row_size = len(matrix)
    col_size = len(matrix[0])
    matrix_2 = [0] * row_size
    for i in range(row_size):
        matrix_2[i] = matrix[i].copy()
    for i in range(row_size):
        for j in range(col_size):
            matrix[i][j] = matrix_2[row_size - 1 - j][i]
    print("***", matrix)
