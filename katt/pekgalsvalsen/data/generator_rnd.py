#!/usr/bin/python3

import sys
import random

default = {
    "n": 100,
    "k": 2,
}

def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    return default[name]

def chars(k):
    itr = (chr(x) for x in range(ord('a'), ord('a') + k))
    return list(itr)

def main():
    random.seed(int(sys.argv[-1]))
    n, k = (int(cmdlinearg(name)) for name in ['n', 'k'])
    print("{} {}".format(n, k))
    ch = chars(k)
    print("".join(ch[random.randint(0,k-1)] for x in range(0, n)))

if __name__ == "__main__":
    main()
