#!/usr/bin/python3

import sys
import random

def sysarg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    raise ValueError('no such argument')

def main():
    random.seed(int(sys.argv[-1]))
    n, l, m = (int(sysarg(c)) for c in 'nlm')
    mode = sysarg('mode')
    if mode == 'linje':
        assert n == m+1
    start_positsions = random.sample(list(range(n), l)

    # TODO

if __name__ == "__main__":
    main()
