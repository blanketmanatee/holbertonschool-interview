#!/usr/bin/python3

""" reads stdin and counts status codes """

import sys


def printstats(dict, file_size):
    """ Prints """
    print("File size: {:d}".format(file_size))
    for i in sorted(dict.keys()):
        if dict[i] != 0:
            print("{}: {:d}".format(i, dict[i]))


status = {"200": 0, "301": 0, "400": 0, "401": 0, "403": 0,
            "404": 0, "405": 0, "500": 0}

count = 0
file_size = 0

try:
    for line in sys.stdin:
        if count != 0 and count % 10 == 0:
            printstats(status, file_size)

        statlist = line.split()
        count += 1

        try:
            file_size += int(statlist[-1])
        except:
            pass

        try:
            if statlist[-2] in status:
                status[statlist[-2]] += 1
        except:
            pass
    printstats(status, file_size)


except KeyboardInterrupt:
    printstats(status, file_size)
    raise
