#!/usr/bin/env python3
import sys

n, m, seed = map(int, sys.argv[1:])

a = []
b = []
it = 0
for i in range(n // 2):
    it += 1
    a.append(it)
for i in range(m):
    it += 1
    b.append(it)
for i in range(n - n // 2):
    it += 1
    a.append(it)

print("{} {}".format(n, m))
print(" ".join(map(str, a)))
print(" ".join(map(str, b)))
