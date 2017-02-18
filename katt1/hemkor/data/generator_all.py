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
n = int(arg('n'))
m = int(arg('m'))
mono = int(arg('mono', 0))
mode = arg('mode', '')

maxw = 2000

print(n, m)
maxp = maxd = 1

for i in range(n):
    p = 1 if mode == 'samep' else random.randint(1, 100000)
    q = random.randint(1, 100)
    maxp = max(maxp, p)
    print(p, q)

for i in range(m):
    v = 1 if mode == 'samev' else random.randint(1, 50) + random.randint(0, 50)
    vr = 1 if mode == 'samev' else v / 100
    d = random.randint(1, 100000)
    maxd = max(maxd, d)
    if i == m-1 and maxd < maxp:
        d = maxp
    if mono:
        # larger cost for higher expiration and for higher value
        k = d / 100000 * vr * maxw + random.triangular(-5.0, 5.0)
    else:
        k = random.uniform(1, maxw) * vr
    k = max(min(round(k), maxw), 1)
    print(v, k, d)
