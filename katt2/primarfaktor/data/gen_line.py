#!/usr/bin/python3

import sys
import random

default = {
    "n": 100,
    "m": 200,
    "maxh": 1000000000,
}

def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    return default[name]

def main():
    random.seed(int(sys.argv[-1]))
    n = int(cmdlinearg('n'))
    maxh = int(cmdlinearg('maxh'))
    m = n-1
    print("{} {}".format(n, m))
    print(" ".join(str(random.randint(0,maxh)) for x in range(0, n)))
    S = set()
    for k in range(0,m):
        print(str(k+1) + " " + str(k+2))
        

if __name__ == "__main__":
    main()



