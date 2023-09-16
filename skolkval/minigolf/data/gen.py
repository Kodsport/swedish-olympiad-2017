#!/usr/bin/env python3

import sys
import random


def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default


random.seed(int(cmdlinearg('seed', sys.argv[-1])))

#testcases:
#40 poäng: inga fler än 7 slag.
#60 poäng: inga ytterligare begränsningar

maxA = int(cmdlinearg("maxA",10))
minA = int(cmdlinearg("minA",1))

n = int(cmdlinearg("n",random.randint(2,10)))

a=[random.randint(minA,maxA) for _ in range(n)]

print(n)
print(*a)
