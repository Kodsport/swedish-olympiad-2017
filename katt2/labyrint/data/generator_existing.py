#!/usr/bin/python3

import sys
import random

def arg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None
    return default

random.seed(int(sys.argv[-1]))
n = int(arg('n'))
m = int(arg('m'))
avoid = int(arg('avoid', 1))
padding = int(arg('padding', 0))
ngood = n - avoid

assert n % 2 == 0
ed = [[] for _ in range(n)]

for col in range(3):
    nodes = list(range(n))
    random.shuffle(nodes)
    for i in range(0, n, 2):
        ed[nodes[i]].append(nodes[i+1])
        ed[nodes[i+1]].append(nodes[i])
for i in range(n):
    assert len(ed[i]) == 3

at = 0
i = 0
s = ""
assert 0 < ngood
assert ed[0][0] < ngood or ed[0][1] < ngood or ed[0][2] < ngood # hopefully true!
while True:
    while True:
        c = random.randint(0, 2)
        if ed[at][c] < ngood:
            break
    s += "RGB"[c]
    assert ed[ed[at][c]][c] == at
    at = ed[at][c]
    i += 1
    if i >= m and at == 0:
        break

s = list(s)
for i in range(padding):
    pos = random.randrange(len(s))
    s[pos:pos] = random.choice(["RR", "GG", "BB"])
s = ''.join(s)
cyc = random.randrange(len(s))
s = s[cyc:] + s[0:cyc]

print(s)
