#!/usr/bin/python3
""" Rotate 2D matrix"""


def rotate_2d_matrix(matrix):
    """ rotate 2D matrix """
    N = len(matrix[0])

    for x in range(N // 2):
        N1 = N - 1
        for y in range(x, N1 - x):
            temp = matrix[x][y]
            matrix[x][y] = matrix[N1 - y][x]
            matrix[N1 - y][x] = matrix[N1 - x][N1 - y]
            matrix[N1 - x][N1 - y] = matrix[y][N1 - x]
            matrix[y][N1 - x] = temp
