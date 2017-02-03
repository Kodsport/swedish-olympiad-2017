#!/usr/bin/python3

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
k = int(arg('k'))
m = int(arg('m'))
assert n <= k <= m

large = 100000000
small = 10000000
rows = []
for i in range(n):
    for j in range(k):
        row.append(random.randint(1, large))
    for j in range(m-k):
        row.append(random.randint(1, small))

rows2 = []
for row in rows:
    r2 = []
    for i in order:
        r2.append(row[i])
    rows2.append(r2)
random.shuffle(rows2)

print("{} {}".format(n, m))
for row in rows2:
    print(" ".join(str(x) for x in row))
