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
l = int(arg('l'))
mode = arg('mode')

node_indexes = list(range(n))
edges = []

def prune_edges(edges):
    ret = []
    counts = set()
    for e in edges:
        u, v, c = e
        assert u != v
        if u > v:
            u, v = v, u
        if (u, v) in counts:
            continue
        counts.add((u, v))
        ret.append(e)
    return ret

if mode == 'line':
    for i in range(n-1):
        edges.append((i, i+1, random.randint(5, 100)))

elif mode == 'nonode':
    assert n <= 200
    ISLAND_SIZE = 10
    assert n % ISLAND_SIZE == 0
    num_islands = n//ISLAND_SIZE

    # within islands
    for i in range(n):
        j = i - (i % ISLAND_SIZE)
        u, v = random.sample(range(j, j + ISLAND_SIZE), 2)
        c = 1 << (i % ISLAND_SIZE)
        edges.append((u, v, c))

    # connecting islands, left to right with increasing costs
    for i in range(num_islands-1):
        a = i * ISLAND_SIZE
        b = a + ISLAND_SIZE
        c = b + ISLAND_SIZE
        u = random.randint(a, b-1)
        v = random.randint(b, c-1)
        c = 10000000 + i*1024
        edges.append((u, v, c))

elif mode == 'normal':
    m = int(arg('m'))
    for i in range(m):
        u, v = random.sample(node_indexes, 2)
        edges.append((u, v, random.randint(5, 10000000)))

else:
    assert False, "invalid mode"

edges = prune_edges(edges)

start_positions = random.sample(node_indexes, l)
m = len(edges)
print("{} {} {}".format(n,l,m))
print('\n'.join(map(str, start_positions)))
for (v1, v2, w) in edges:
    print("{} {} {}".format(v1, v2, w))
