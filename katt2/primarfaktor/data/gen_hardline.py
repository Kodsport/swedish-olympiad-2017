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

    for i in range(0,n):
        if i == 0:
            h = maxh
        elif i%2 == 1:
            h = maxh//2 - i//2
        else:
            h = maxh//2 + i//2
        if(i < n-1):
            print(h , end=" ")
        else:
            print(h)
    
    for k in range(0,m):
        print(str(k+1) + " " + str(k+2))
        

if __name__ == "__main__":
    main()
