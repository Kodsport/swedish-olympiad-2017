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
    karta_t = [list(x) for x in zip(*karta)]
    best = 99999999999999999999999999
    for y0 in range(r-l+1):
        y1 = y0 + l
        for x0 in range(c-l+1):
            #print(y0, x0)
            x1 = x0 + l
            nums_xled = karta[y0][x0:x1] + karta[y1-1][x0:x1]
            nums_yled = karta_t[x0][y0:y1] + karta_t[x1-1][y0:y1]
            nums = nums_xled + nums_yled
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
