import sys
import random

n,m,seed = map(int, sys.argv[1:])
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
        r = random.randint(0, 3)
        if r == 0 and hasb >= 2 and len(a)+2 <= n and len(b)+2 <= m:
            a.append(cur)
            a.append(cur)
            b.append(cur)
            b.append(cur)
            break
        elif r == 1 and hasb >= 1 and len(a) < n and len(b) < m:
            a.append(cur)
            b.append(cur)
            break
        elif r == 2 and hasb >= 1 and len(a) < n:
            a.append(cur)
            hasb -= 1
            break
        elif r == 3 and len(b) < m:
            b.append(cur)
            hasb += 1
            break

assert len(a) == n
assert len(b) == m

print("{} {}".format(n,m))
print(" ".join(map(str, a)))
print(" ".join(map(str, b)))
