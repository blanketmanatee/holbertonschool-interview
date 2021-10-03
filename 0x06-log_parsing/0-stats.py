#!/usr/bin/python3

""" reads stdin and parses"""

if __name__ == "__main__":
    import sys
    import signal

    c = fileSize = 0
    statCount = {"200": 0, "301": 0, "400": 0, "401": 0, "403": 0, "404": 0, "405": 0, "500": 0}

    def parseIt(statCount, fileSize):
        print("File size: {}".format(fileSize))
        for key in sorted(statCount.keys()):
            if statCount[key] == 0:
                continue
            print("{}: {}".format(key, statCount[key]))

    try:
        for line in sys.stdin:
            c += 1
            split = line.split(" ")
            try:
                status = spli[-2]
                fileSize += int(split[-1])

                if status in statCount:
                    statCount[status] += 1
            except Exception:
                pass

            if c % 10 == 0:
                parseIt(statCount, fileSize)

        else: parseIt(statCount, fileSize)

    except (KeyboardInterrupt, SystemExit):
        parseIt(statCount, fileSize)
        raise