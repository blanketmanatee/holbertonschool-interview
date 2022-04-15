#!/usr/bin/python3
"""
Pascal Triangle
"""


def pascal_triangle(n):
    """Pascal Triangle"""
    if n <= 0:
        return []

    pascal = [[1]]
    while len(pascal) != n:
        previous = pascal[-1]
        current = [1]
        for i in range(len(previous) - 1):
            current.append(previous[i] + previous[i + 1])
        current.append(1)
        pascal.append(current)
    return pascal
