#!/usr/bin/python3
"""
Log parsing script
Reads stdin line by line and computes metrics
"""

import sys
import re


LOG_PATTERN = re.compile(
    r'^\S+ - \[.*\] "GET /projects/260 HTTP/1\.1" (?P<status>\d{3}) (?P<size>\d+)$'
)


def print_stats(total_size, status_codes):
    """
    Prints computed statistics
    """
    print("File size: {}".format(total_size))
    for code in sorted(status_codes.keys()):
        if status_codes[code] != 0:
            print("{}: {}".format(code, status_codes[code]))


if __name__ == "__main__":
    total_size = 0
    status_codes = {
        "200": 0,
        "301": 0,
        "400": 0,
        "401": 0,
        "403": 0,
        "404": 0,
        "405": 0,
        "500": 0
    }

    count = 0

    try:
        for line in sys.stdin:
            match = LOG_PATTERN.match(line.rstrip())
            if match is None:
                continue

            total_size += int(match.group("size"))

            code = match.group("status")
            if code in status_codes:
                status_codes[code] += 1

            count += 1

            if count % 10 == 0:
                print_stats(total_size, status_codes)

        print_stats(total_size, status_codes)

    except KeyboardInterrupt:
        print_stats(total_size, status_codes)
        raise
