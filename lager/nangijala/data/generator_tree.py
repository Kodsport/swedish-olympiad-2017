#!/usr/bin/python3

from __future__ import print_function
import sys
import random

def arg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None
    return default

random.seed(int(arg('seed', sys.argv[-1])))
n = int(arg('n'))

ed = []
for i in range(n-1):
    ed.append((i+1, random.randrange(i+1)))
random.shuffle(ed)

print(n, n-1)
for (a, b) in ed:
    if random.choice([True, False]):
        print(a, b)
    else:
        print(b, a)
