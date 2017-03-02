#!/usr/bin/python3

import sys
import random

def arg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None
    return default

random.seed(int(sys.argv[-1]))
m = int(arg('m'))
padding = int(arg('padding', 0))

s = ''.join(random.choice("RGB") for _ in range(m))
s = list(s)
for i in range(padding):
    pos = random.randrange(len(s))
    s[pos:pos] = random.choice(["RR", "GG", "BB"])
s = ''.join(s)
cyc = random.randrange(len(s))
s = s[cyc:] + s[0:cyc]

print(s)
