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
    n3 = n//3
    n -= n%3
    m = n-1
    print("{} {}".format(n, m))

    I = list(range(0,n))
    random.shuffle(I)
    htemp = []
    H = []
    for i in range(0,n):
        htemp.append(random.randint(0,maxh))
        H.append(0)
    htemp.sort()
    for i in range(0,n):
        H[I[i]] = htemp[i]
    print(" ".join(str(H[x]) for x in range(0,n)))
    for i in range(0,n3):
        print(str(I[i]+1) + " " + str(I[i+n3]+1))
        print(str(I[i]+1) + " " + str(I[i+2*n3]+1))
    for i in range(0,n3-1):
        print(str(I[i+n3]+1) + " " + str(I[i+1+n3]+1))

if __name__ == "__main__":
    main()



