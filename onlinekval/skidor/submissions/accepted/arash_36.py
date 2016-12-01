#! /usr/bin/python3
"""
Arash AC(36) solution to skidor (brute force)
"""
import sys
from pprint import pprint


def main():
    stdin_lines = []
    for line in sys.stdin:
        if line.strip() != "":
            stdin_lines.append(line.strip())

    # parse step 1
    r, c, l = map(int, stdin_lines[0].split())
    # parse step 2
    karta = list(map(lambda line: list(map(int, line.split())), stdin_lines[1:]))
    # Done parsing, start solving
    best = 99999999999999999999999999
    for y0 in range(r-l+1):
        y1 = y0 + l
        for x0 in range(c-l+1):
            #print(y0, x0)
            x1 = x0 + l
            nums = sum(map(lambda line: line[x0:x1], karta[y0:y1]), [])
            maxx = max(nums)
            minn = min(nums)
            if minn > -1:
                diff = maxx - minn
                if diff < best:
                    best = diff
                    best_y, best_x = (y0, x0)
    print(best_y, best_x)


if __name__ == '__main__':
    main()
