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

def twop(i):
    ans = 0
    i2=i
    while i2%2 == 0:
        i2 = i2//2
        ans += 1
    return ans

def main():
    random.seed(int(sys.argv[-1]))
    n = int(cmdlinearg('n'))
    maxh = int(cmdlinearg('maxh'))
    m = n-1
    print("{} {}".format(n, m))
    print(" ".join(str(twop(x+1)+(x>n//2)) for x in range(0,n)))
    for k in range(0,m):
        print(str(k+1) + " " + str(k+2))
        

if __name__ == "__main__":
    main()
