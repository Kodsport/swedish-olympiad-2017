#!/usr/bin/env python3

import sys
import random as rnd


def getArg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        sys.exit(1)
    return default


T: int = int(getArg(name="T", default=sys.argv[-1]))
N: int = int(getArg(name="N", default=100_000))
W: int = int(getArg(name="W", default=1000))

lo: int = int(getArg(name="lo", default=1))
hi: int = int(getArg(name="hi", default=W))

# Coz weird legacy shit
rnd.seed(T if T != 10 else 5)


def gen_rnd():
    return [rnd.randint(lo, hi) for _ in range(N)]


def t1():
    blocks = [W] * (2 * N // 3) + [1] * (N - 2 * N // 3)
    return blocks


def t3():
    blocks = (
        [W] * 500
        + [rnd.randint(1, 30) for _ in range(3000)]
        + [rnd.randint(31, W) for _ in range(1500)]
    )
    return blocks


def t4():
    blocks = [rnd.randint(150, 250) for _ in range(400)] + [
        rnd.randint(4, 6) for _ in range(600)
    ]
    return blocks


def t6():
    blocks = [*range(1, 100_000 + 1)]
    return blocks


def t10():
    blocks = [1 << rnd.randint(0, 9) for _ in range(100_000)]
    return blocks


# Print result
print(T if T != 10 else 5, N, W)

blocks = eval("gen_rnd()" if T in (2, 5, 7, 8, 9) else f"t{T}()")  # ...

rnd.shuffle(blocks)
assert len(blocks) == N
print(*blocks)
