#!/usr/bin/python3

# Kills greedy / exchange-argument solutions.
#
# Both modes build an instance whose optimum forces an exact mix of two different
# department "shapes", with the computers running out precisely when the mix is right.
# A solution that hands out departments one at a time -- always taking the locally
# cheapest way to reach the previous department's value -- commits to the wrong shape
# early and can never recover, so it reports a value that is too low (or, if its
# feasibility check is also broken, one that cannot actually be paid for at all).
# Getting these right needs a real search over how many departments use each shape.
#
# mode=tight31  (fits every group)
#   Prices satisfy 2a <= b < 3a, so the answer is 3a and a department is either
#   "3 cheap" or "1 cheap + 1 expensive" -- the expensive computer is worth two cheap
#   ones but not three. If k departments take the mixed shape, the cheap computers used
#   are k + 3*(n-k), so the packing is tight exactly when
#       x = 3n - 2y.
#   That relation, not the particular prices, is what makes the instance bite: every
#   ratio in [2,3) works.
#
# mode=tight13  (needs (x+y)/n = 3.6, so it does not fit group 4, where n is too large)
#   Prices satisfy a < b <= 3a/2, so the answer is 3b and a department is either
#   "3 expensive" or "3 cheap + 1 expensive". With x = y the packing is tight when
#       n = 5x/9.
#   This is the only one of the two that also defeats a heap greedy which substitutes
#   cheap computers for expensive ones one at a time: the marginal cost of such a swap
#   is a ceil(), so it is not convex, and the cheapest first swap is not on the path to
#   the cheapest overall mix.

import sys

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        sys.exit(1)
    return default

mode = cmdlinearg('mode')
a = int(cmdlinearg('a'))
b = int(cmdlinearg('b'))

if mode == 'tight31':
    n = int(cmdlinearg('n'))
    y = int(cmdlinearg('y'))
    x = 3 * n - 2 * y
    if not 2 * a <= b < 3 * a:
        print(f"tight31 needs 2a <= b < 3a, got a={a} b={b}", file=sys.stderr)
        sys.exit(1)
elif mode == 'tight13':
    x = int(cmdlinearg('x'))
    y = x
    n = 5 * x // 9          # floor: one department more and the computers no longer run out exactly
    if not a < b <= 3 * a // 2:
        print(f"tight13 needs a < b <= 3a/2, got a={a} b={b}", file=sys.stderr)
        sys.exit(1)
else:
    print("unknown mode", mode)
    sys.exit(1)

if x < 0:
    print(f"mode {mode} produced x={x}; pick n and y with 3n >= 2y", file=sys.stderr)
    sys.exit(1)

print(x, a, y, b, n)
