#!/usr/bin/python3
''' can all boxes be unlocked '''


def canUnlockAll(boxes):
    ''' create a list of keys '''
    if type(boxes) is not list:
        return False
    elif (len(boxes)) == 0:
        return False
    for k in range(1, len(boxes) - 1):
        seen = False
        for idx in range(len(boxes)):
            seen = k in boxes[idx] and k != idx
            if seen:
                break
        if seen is False:
            return seen
    return True
