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
sym = int(arg('s', 1))
mode = arg('mode', '')

lim = 10**6
s = [random.randint(1, lim) for _ in range(n)]
d = [[random.randint(1, lim) for _ in range(n)] for _ in range(n)]
if mode == 'dsame':
    r = random.randint(1, lim)
    d = [[r] * n for _ in range(n)]
elif mode == 'ssame':
    r = random.randint(1, lim // n * 2)
    s = [r] * n
for i in range(n):
    d[i][i] = 0
if sym:
    for i in range(n):
        for j in range(n):
            d[i][j] = d[j][i]

print(n)
print(*s)
for i in range(n):
    print(*d[i])
