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
unweighted = int(arg('unw', 0))
small = int(arg('small', 0))

node_indexes = list(range(n))
start_positions = random.sample(node_indexes, l)
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
    assert not unweighted
    for i in range(n-1):
        edges.append((i, i+1, random.randint(5, 100)))

elif mode == 'nonode':
    assert not unweighted
    ISLAND_SIZE = 10
    assert n % ISLAND_SIZE == 0
    num_islands = n//ISLAND_SIZE

    # within islands
    for i in range(n):
        j = i // ISLAND_SIZE * ISLAND_SIZE
        u, v = random.sample(range(j, j + ISLAND_SIZE), 2)
        c = 2 ** (i % ISLAND_SIZE + 1) # <= 1024
        edges.append((u, v, c))

    # connecting islands, left to right with odd costs
    for i in range(num_islands-1):
        a = i * ISLAND_SIZE
        u = random.randrange(ISLAND_SIZE) + a
        v = random.randrange(ISLAND_SIZE) + a + ISLAND_SIZE
        c = random.randint(1, 1997) | 1
        edges.append((u, v, c))

    # sample islands with odd difference when in sorted order
    max_isl = num_islands // 2
    start_isl = sorted(random.sample(range(max_isl), min(l * 2 // 3, max_isl)))
    candidates = []
    for i in range(len(start_isl)):
        isl = start_isl[i] * 2 + (i % 2)
        for j in range(ISLAND_SIZE):
            candidates.append(isl * ISLAND_SIZE + j)
    start_positions = random.sample(candidates, l)

elif mode == 'islands':
    ISLAND_SIZE = 10
    assert n % ISLAND_SIZE == 0
    num_islands = n//ISLAND_SIZE

    # within islands
    for i in range(n):
        j = i // ISLAND_SIZE * ISLAND_SIZE
        u, v = random.sample(range(j, j + ISLAND_SIZE), 2)
        edges.append((u, v, 1 if unweighted else random.randint(1, 1000)))

    # connecting islands, left to right with cost 1
    for i in range(num_islands-1):
        a = i * ISLAND_SIZE
        u = random.randrange(ISLAND_SIZE) + a
        v = random.randrange(ISLAND_SIZE) + a + ISLAND_SIZE
        edges.append((u, v, 1 if unweighted else random.randint(1, 1000)))

elif mode == 'random':
    m = int(arg('m'))
    for i in range(m):
        u, v = random.sample(node_indexes, 2)
        edges.append((u, v, 1 if unweighted else random.randint(5, 1000)))

else:
    assert False, "invalid mode"

edges = prune_edges(edges)

order = list(range(n))
if mode != 'line':
    random.shuffle(order)

if small:
    assert n <= 2000
    assert len(edges) <= 2000

print("{} {} {}".format(n,l,len(edges)))
print('\n'.join(str(order[x]) for x in start_positions))
for (v1, v2, w) in edges:
    print("{} {} {}".format(order[v1], order[v2], w))
