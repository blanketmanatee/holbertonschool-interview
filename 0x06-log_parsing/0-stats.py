#!/usr/bin/python3

""" reads stdin and parses"""

if __name__ == "__main__":
    import sys
    import signal

    file_size = [0]
    count = 1
    statCount = {"200": 0, "301": 0, "400": 0, "401": 0,
                 "403": 0, "404": 0, "405": 0, "500": 0}

    def parseIt():
        print("File size: {}".format(file_size[0]))
        for key in sorted(statCount.keys()):
            if statCount[key] != 0:
                print("{}: {}".format(key, statCount[key]))

    def stdin_parse(line):
        """
        checks stdin
        """
        try:
            line = line[:-1]
            word = line.split(' ')
            file_size[0] += int(word[-1])
            status_code = int(word[-2])
            if status_code in status_codes:
                status_codes[status_code] += 1
        except BaseException:
            pass

    try:
        for line in sys.stdin:
            stdin_parse(line)
            if count % 10 == 0:
                parseIt()
            count += 1
    except KeyboardInterrupt:
        parseIt()
        raise
    parseIt()