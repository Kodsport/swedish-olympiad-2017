#!/usr/bin/python3

import sys
import random

default = {
    "n": 50,
    "m": 100000,
    "max_bi": 10**15,
}

def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    return default[name]


def main():
    random.seed(int(sys.argv[-1]))
    n, m, max_bi = (int(cmdlinearg(name)) for name in ['n', 'm', 'max_bi'])
    print("{} {}".format(n, m))
    print(" ".join(str(random.randint(42*m/100, 90*m/100)) for i in range(n)))
    print(" ".join(str(random.randint(0, max_bi)) for i in range(m)))

if __name__ == "__main__":
    main()
