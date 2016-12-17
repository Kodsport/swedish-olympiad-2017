#!/usr/bin/python3

import sys
import random


def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    return None  # This is ok for this task

def mint(x):
    if x:
        return int(x)

def main():
    random.seed(int(sys.argv[-1]))
    n, l, m = (mint(cmdlinearg(c)) for c in 'nlm')
    print("TODO för kubiska boxar")


if __name__ == "__main__":
    main()
