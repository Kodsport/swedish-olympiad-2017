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
    random.shuffle(ch)
    fixed = 0
    out = ""
    rnd = list(random.randint(0, n) for x in range(0,k-1))
    sm = int(sum(rnd) + n/2)
    for i in range(0,k-1):
        r = int(n*rnd[i]/sm)
        fixed += r
        out += "".join(ch[i]*r)
    out += "".join(ch[k-1]*(n-fixed))
    print(out)

if __name__ == "__main__":
    main()
