#!/usr/bin/python3

# Kills memoised search over the state (departments left, desktops left, laptops left,
# value of the previous department), which is what a search-based solution decays into.
# Three things have to hold at once:
#
#   * n as small as the group allows and x = y = maxXY, so (x+y)/n is as large as possible.
#     Each department can then afford several computers, and the "the value still to hand out
#     is at least (departments left) * (previous value)" bound stops cutting the recursion.
#
#   * b/a large. A department paid for with cheap computers alone needs about b/a of them,
#     so a search that enumerates how many cheap computers a department gets branches that wide.
#
#   * gcd(a, b) = 1 with a > 1. The cheapest value that reaches the previous department's value
#     then keeps rounding up onto a *new* number, so the "previous value" coordinate of the state
#     drifts through a huge number of distinct values and the memo table explodes.
#     This is the point that also kills a search enumerating the *expensive* computer instead:
#     with a = 1 that rounding is exact, the previous value never drifts, and the state space
#     stays small.

import sys
from math import gcd


def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        sys.exit(1)
    return default


n = int(cmdlinearg('n'))
maxXY = int(cmdlinearg('maxXY'))
a = int(cmdlinearg('a', 3))
ratio = int(cmdlinearg('ratio', 33))

b = a * ratio
while gcd(a, b) != 1:
    b += 1

if not 1 <= a < b <= 1000:
    print(f"prices a={a} b={b} are outside 1..1000", file=sys.stderr)
    sys.exit(1)

print(maxXY, a, maxXY, b, n)
