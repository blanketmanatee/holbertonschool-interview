#!/usr/bin/python3


def rain(walls):
    arr = [];
    res = 0;

    for i in range(1, walls - 1):

        left = arr[i];
        for j in range (i) :
            left = max(left, arr[j]);

        right = arr[i];

        for j in range(i + 1, walls):
            right = max(right, arr[j]);
        res = res + (min(left, right) - arr[i]);
    return res;