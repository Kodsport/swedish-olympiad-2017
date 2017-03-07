#!/usr/bin/python3

import sys
import random

default = {
    "n": 997
}

def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    return default[name]

def main():
    c, k, n = (int(cmdlinearg(name)) for name in ['c', 'k', 'n'])
    random.seed(int(sys.argv[-1]))
    x = ''.join(random.choice(['0', '1']) for i in range(c * n))
    print("{} {} {}".format(c, k, n))
    print(x)
    i = ' '.join(str(_) for _ in random.sample(range(k), c))
    print(i)

if __name__ == "__main__":
    main()
