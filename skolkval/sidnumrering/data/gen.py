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

n = int(cmdlinearg("n",random.randint(int(cmdlinearg("minN",1)),int(cmdlinearg("maxN",10**12)))))

print(n)
