#!/usr/bin/python3
"""Rain barrels"""


def rain(walls):
    """fill the rain barrels"""
    size = len(walls)
    if size == 0 or size == 1 or size == 2:
        return 0

    rain = 0
    while size >= 3:
        w = walls.copy()
        w.sort()
        top = w[-1]
        top2 = w[-2]
        x = walls.index(top)
        y = walls.index(top2)
        if x == y:
            y = walls.index(top2, y + 1)
        idx = [x, y]
        idx.sort()
        limit = min([walls[idx[0]]], walls[idx[1]])
        for i in range(idx[0] + 1, idx[1]):
            rain += limit - walls[i]
        for i in range(idx[0], idx[1]+1):
            del walls[idx[0]]
        walls.insert(idx[0], limit)
        res = len(walls)
    return rain
