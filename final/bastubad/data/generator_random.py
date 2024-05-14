#!/usr/bin/python3

import math
import sys
import random

def arg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

# t is either convex, concave, or probability of convex (lower = more concave = more interesting?)
tp = arg('t')
if tp == 'convex':
    choose_convex = lambda: True
elif tp == 'concave':
    choose_convex = lambda: False
else:
    prob = float(tp)
    choose_convex = lambda: random.random() < prob

random.seed(int(arg('seed', sys.argv[-1])))
n = int(arg('n'))
cap = int(arg('cap', -1))

eachy = 500000000
minx = 100
maxx = 10000
midp = random.uniform(minx, maxx - minx)
stuff = []

for i in range(n):
    peak = random.triangular(midp/2, maxx, midp)
    hiy = int(random.triangular(eachy/2, eachy*3/2, eachy))
    loy = int(random.triangular(1, hiy/5, hiy/10))
    # f(x) = hiy - d * (x - peak)^2
    # s.t. f(0) = loy, f(peak) = hiy
    # or possibly the reverse
    # hiy - d * peak^2 = loy
    if choose_convex():
        hiy, loy = loy, hiy
    d = (hiy - loy) / peak**2
    assert d != 0
    # d ~ 5e8 / 1e4 ** 2 ~ 5
    a = int(math.ceil(-d))
    b = int(2*d*peak)
    c = hiy - int(d*peak*peak)
    c = max(c, 1)
    assert c < 10**9
    if cap != -1:
        t = cap
        if a*cap*cap + b*cap + c <= 0:
            continue
    else:
        while True:
            t = random.randint(1, maxx*2)
            if a*t*t + b*t + c > 0:
                break
    stuff.append((a,b,c,t))

print(len(stuff))
for (a,b,c,t) in stuff:
    print("{} {} {} {}".format(a,b,c,t))
