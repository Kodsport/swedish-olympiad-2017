#!/usr/bin/env python3
import sys
import random

n, m, c, rev, seed = map(int, sys.argv[1:])
random.seed(seed)

assert c <= n
assert c <= m
cn = random.randint(0, c)
cm = random.randint(0, c)
lim = (n + m) * 5
common = lim // 2
a = [common] * cn + sorted([random.randint(common + 1, lim) for _ in range(n - cn)])
b = sorted([random.randint(1, common - 1) for _ in range(m - cm)]) + [common] * cm
if rev:
    n, m = m, n
    a, b = b, a

print("{} {}".format(n, m))
print(" ".join(map(str, a)))
print(" ".join(map(str, b)))
