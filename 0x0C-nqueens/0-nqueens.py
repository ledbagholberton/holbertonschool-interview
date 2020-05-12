#!/usr/bin/python3
""" N - Queens"""
import sys


def not_safe(board, i, j, fil):
    """Function verify if pos(i,j) is safe for queen"""
    if ((board[i] is j) or
       (board[i] is j-i+fil) or
       (board[i] is i-fil+j)):
        return True
    return False


def solve(board, fil, n):
    """ solve function"""
    if (fil is n):
        show_sol(board, n)
    else:
        for j in range(n):
            flag = True
            for i in range(fil):
                if not_safe(board, i, j, fil):
                    flag = False
            if flag:
                board[fil] = j
                solve(board, fil+1, n)


def show_sol(board, n):
    """function print solutions"""
    list = []
    for i in range(n):
        for j in range(n):
            if j is board[i]:
                list.append([i, j])
    print(list)


if len(sys.argv) is not 2:
    print("Usage: nqueens N")
    sys.exit(1)
try:
    n = int(sys.argv[1])
except BaseException:
    print("N must be a number")
    sys.exit(1)
if (int(sys.argv[1]) < 4):
    print("N must be at least 4")
    sys.exit(1)
else:
    n = int(sys.argv[1])
board = [0 * n for i in range(n)]
fil = 0
solve(board, fil, n)
