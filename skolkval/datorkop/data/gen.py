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


n = int(cmdlinearg("n", 1000))
maxXY = int(cmdlinearg("maxXY", 1000))

print(random.randint(0,maxXY), random.randint(1,1000), random.randint(0,maxXY), random.randint(1,1000), n)


