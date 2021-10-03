#!/usr/bin/python3
import sys
import signal

""" reads stdin by line and checks status codes """

if __name__ =="__main__":

    c = filesize = 0
    status = {"200": 0, "301": 0, "400": 0, "401": 0, "403": 0, "404": 0, "405": 0, "500": 0}

    def handleten (status, filesize):
        print("File size: {}:".format(filesize))
        for key in sorted(status.keys()):
            if status[key] == 0:
                continue
            print("{}: {}".format(key, status[key]))

    try:
        for line in sys.stdin:
            c+=1
            split = line.split(" ")
            try:
                boop = split[-2]
                filesize += int(split[-1])

                if boop in status:
                    status[boop] += 1
            except Exception:
                pass

            if c % 10 == 0:
                handleten(status, filesize)
        else:
            handleten(status, filesize)
    except (keyboardinterrupt, systemexit):
        handleten(status, filesize)
        raise
