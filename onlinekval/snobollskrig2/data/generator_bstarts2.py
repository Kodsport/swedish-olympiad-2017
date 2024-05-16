#!/usr/bin/env python3
import sys
import random

n, m, seed = map(int, sys.argv[1:])
random.seed(seed)

a = []
b = []
hasb = 0
nrem = n
mrem = m
assert n <= m
cur = 0
while len(a) < n or len(b) < m:
    cur += 1
    while True:
        r = random.randint(2, 3)
        if r == 2 and hasb >= 1 and len(a) < n:
            a.append(cur)
            hasb -= 1
            break
        elif r == 3 and len(b) < m:
            b.append(cur)
            hasb += 1
            break

assert len(a) == n
assert len(b) == m

print("{} {}".format(n, m))
print(" ".join(map(str, a)))
print(" ".join(map(str, b)))
