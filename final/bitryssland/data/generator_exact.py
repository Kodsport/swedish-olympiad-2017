#!/usr/bin/python3

import sys
import random

default = {
    "n": 50,
    "m": 100000,
    "max_bi": 10**15,
}

def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    return default[name]

def compute_exact(n, ms):
    ans = [0] * n
    for i in range(n):
        for j in range(len(ms)):
            if ms[j] % 2 == 1:
                ans[i] += 1
            ms[j] //= 2
    return ans

def domoves(A):
    for i in range(len(A) - 1):
        w = len(A) - i - 1
        mod = random.randint(0, A[w])
        A[w] -= mod
        A[w - 1] += 2 * mod

def main():
    random.seed(int(sys.argv[-1]))
    n, m, max_bi = (int(cmdlinearg(name)) for name in ['n', 'm', 'max_bi'])
    print("{} {}".format(n, m))
    B = [random.randint(0, max_bi) for i in range(m)]
    A = compute_exact(n, list(B))
    if 'move' in sys.argv:
        domoves(A)
    print(" ".join(str(x) for x in A))
    print(" ".join(str(x) for x in B))

if __name__ == "__main__":
    main()
