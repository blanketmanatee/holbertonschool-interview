#!/usr/bin/python3


"""
Write a method that determines if a given data set
represents a valid UTF-8 encoding.
"""


def validUTF8(data):
    """
    def validUTF8(data)
    """

    n_bytes = 0

    a = 1 << 7
    b = 1 << 6

    for num in data:
        a = 1 << 7
        if n_bytes == 0:
            while a & num:
                n_bytes += 1
                a = a >> 1
            if n_bytes == 0:
                continue
            if n_bytes == 1 or n_bytes > 4:
                return False
        else:
            if not (num and a and not (num & b)):
                return False
            n_bytes -= 1
        return n_bytes == 0
