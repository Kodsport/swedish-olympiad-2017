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

    rnd = list(random.randint(0, n) for x in range(0,10))
    sm = int(k*(sum(rnd) + n/2))
    out = ""
    fixed = 0
    for r in rnd:
        ch = chars(k)
        random.shuffle(ch)
        rounds = int(r*n/sm)
        fixed += k*rounds
        perm = ''.join(ch)
        out += ''.join(perm for i in range(0,rounds))
    ch = chars(k)
    out += ''.join(ch[random.randint(0,k-1)] for x in range(0, n-fixed))
    print(out)

if __name__ == "__main__":
    main()
