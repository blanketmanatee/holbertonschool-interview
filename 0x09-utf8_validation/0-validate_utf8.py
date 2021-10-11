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

    m1 = 1 << 7
    m2 = 1 << 6

    for num in data:
        m = 1 << 7
        if n_bytes == 0:
            while m & num:
                n_bytes += 1
                m = m >> 1
            if n_bytes == 0:
                continue
            if n_bytes == 1 or n_bytes > 4:
                return False
        else:
            if not (num and m1 and not (num & m2)):
                return False
            n_bytes -= 1
        return n_bytes == 0
