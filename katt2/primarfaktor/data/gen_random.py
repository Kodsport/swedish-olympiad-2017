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
    n, m = (int(cmdlinearg(name)) for name in ['n', 'm'])
    maxh = int(cmdlinearg("maxh"))
    print("{} {}".format(n, m))
    print(" ".join(str(random.randint(0,maxh)) for x in range(0, n)))
    S = set()
    for k in range(0,m):
        i = random.randint(0,n+1)
        j = random.randint(0,n+1)
        while not (i != j and (max(i,j)*n+min(i,j)) not in S):
            i = random.randint(0,n+1)
            j = random.randint(0,n+1)
        S.add(max(i,j)*n+min(i,j))
        print(str(i+1) + " " + str(j+1))
        

if __name__ == "__main__":
    main()
