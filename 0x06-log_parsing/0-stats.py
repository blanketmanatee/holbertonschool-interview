#!/usr/bin/python3

""" reads stdin and parses"""

if __name__ == "__main__":
    import sys
    import signal

    file_size = [0]
    codes = [200, 301, 400, 401, 403, 404, 405, 500]
    count = 0
    size = 0
    statCount = {'200': 0, '301': 0, '400': 0, '401': 0,
                 '403': 0, '404': 0, '405': 0, '500': 0}

    try: 
        for ln in sys.stdin:
            if count == 10:
                print("File size: {}".format(file_size))
            for key in sorted(statCount):
                print("{}: {}".format(key, statCount[key]))
            count = 1
        else: count += 1

        ln = ln.split()

        try:
            size = size + int(ln[-1])
        except (IndexError, ValueError):
            pass

        try:
            if ln[-2] in statCount:
                if codes.get(ln[-2], -1) == -1:
                    codes[ln[-2]] = 1
                else:
                    codes[ln[-2]] += 1
        except IndexError:
            pass

        print("File size: {}".format(file_size))
        for key in sorted(codes):
            print("{}: {}".format(key, codes[key]))


    
    except KeyboardInterrupt:
        print("File size:{}".format(file_size))
        for key in sorted(statCount):
            print("{}: {}".format(key, statCount[key]))
        raise
