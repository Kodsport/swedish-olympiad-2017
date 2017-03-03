#!/usr/bin/python3

import sys
import random

default = {
    "n": 100000,
    "m": 100000,
}

def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    return default[name]

def main():
    random.seed(int(sys.argv[-1]))
    n, m = (int(cmdlinearg(name)) for name in ['n', 'm'])
    assert m > 1
    print("{} {}".format(n, m))
    shuffleNodes = [i for i in range(0, n)]
    random.shuffle(shuffleNodes)
    for i in range(0, m-1):
        print("{} {}".format(shuffleNodes[i], shuffleNodes[i+1]))
    print("{} {}".format(shuffleNodes[m-1], shuffleNodes[0]))

if __name__ == "__main__":
    main()
