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
dup = int(arg('dup', 1))
if not dup:
    assert not padding

s = random.choice("RGB")
for i in range(m-1):
    c = random.choice("RGB")
    if not dup:
        while c == s[-1] or (i == m-2 and c == [0]):
            c = random.choice("RGB")
    s += c

s = list(s)
for i in range(padding):
    pos = random.randrange(len(s))
    s[pos:pos] = random.choice(["RR", "GG", "BB"])
s = ''.join(s)
cyc = random.randrange(len(s))
s = s[cyc:] + s[0:cyc]

print(s)
