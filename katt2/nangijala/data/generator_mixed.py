#!/usr/bin/python3

import sys
import random

default = {
    "n": 100000,
    "m": 100000,
    "s": 10,
}

def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    return default[name]

def path(start, end, shuffleNodes):
    assert end - start > 0
    for i in range(start, end-1):
        print("{} {}".format(shuffleNodes[i], shuffleNodes[i+1]))

def cycle(start, end, shuffleNodes):
    assert end - start > 1
    for i in range(start, end-1):
        print("{} {}".format(shuffleNodes[i], shuffleNodes[i+1]))
    print("{} {}".format(shuffleNodes[end-1], shuffleNodes[start]))

def main():
    random.seed(int(sys.argv[-1]))
    n, m, s = (int(cmdlinearg(name)) for name in ['n', 'm', 's'])
    print("{} {}".format(n, m))
    shuffleNodes = [i for i in range(0, n)]
    random.shuffle(shuffleNodes)
    i = 0
    isCycle = True
    while m > 0:
        if isCycle and m > 2:
            length = min(s, m)
            cycle(i, i+length, shuffleNodes)
            m -= length
            i += length
            isCycle = False
        else:
            length = min(s, m+1)
            path(i, i+length, shuffleNodes)
            m -= length - 1
            i += length
            isCycle = True
    assert m == 0

if __name__ == "__main__":
    main()
