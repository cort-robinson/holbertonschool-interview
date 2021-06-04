#!/usr/bin/python3
"""log parsing module"""
import sys
import re


def print_codes(total_size, codes):
    print("File size: {:d}".format(total_size))
    for key in sorted(codes.keys()):
        if (codes[key]):
            print("{:s}: {:d}".format(key, codes[key]))


if __name__ == '__main__':
    ptn = re.compile('.+ .+ \d+')
    total_size = 0
    codes = {'200': 0, '301': 0,
             '400': 0, '401': 0,
             '403': 0, '404': 0,
             '405': 0, '500': 0}

    try:
        timeout = 10
        for line in sys.stdin:
            if (ptn.match(line)):
                values = line.split('"')[2].split()
                total_size += int(values[1])
                if values[0] in codes.keys():
                    codes[values[0]] += 1
                timeout -= 1
                if timeout < 1:
                    print_codes(total_size, codes)
                    timeout = 10
        print_codes(total_size, codes)
    except KeyboardInterrupt:
        print_codes(total_size, codes)
        sys.exit(0)
