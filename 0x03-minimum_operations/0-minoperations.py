#!/usr/bin/python3
"""
Function of minOperations(n)
"""


def minOperations(n):
    """
    find the minoperations
    """
    if n <= 1:
        return 0

    divide = 2
    operate = 0
    quotient = n
    while quotient > 1:
        if (quotient % divide) == 0:
            quotient = quotient // divide
            operate += divide
        else:
            divide += 1
    return operate
