#!/usr/bin/env python3
import sys
import random

n, m, seed = map(int, sys.argv[1:])
random.seed(seed)

li = [random.randint(1, 7) for _ in range(n + m)]
a = sorted(li[0:n])
b = sorted(li[n:])

print("{} {}".format(n, m))
print(" ".join(map(str, a)))
print(" ".join(map(str, b)))
