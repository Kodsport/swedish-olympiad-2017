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
m = int(arg('m', -1))
mode = arg('mode')
node_indexes = list(range(n))

if mode == 'line':
    assert m == -1
    m = n-1

    def edge(i):
        return (i, i+1)

    def weight(i):
        return random.randint(5, 100)
elif mode == 'nonode':
    assert m == -1
    assert n <= 200
    ISLAND_SIZE = 10
    assert n % ISLAND_SIZE == 0
    num_islands = n//ISLAND_SIZE
    m = n + num_islands-1

    def edge(i):
        if i < n:
            # within an island
            j = i - (i % ISLAND_SIZE)
            return random.sample(range(j, j + ISLAND_SIZE), 2)
        else:
            # connecting islands (left to right)
            a = (i-n)*ISLAND_SIZE
            b = a + ISLAND_SIZE
            c = b + ISLAND_SIZE
            return (random.randint(a, b-1), random.randint(b, c-1))

    def weight(i):
        if i < n:
            # within an island
            return 1 << (i % ISLAND_SIZE)
        else:
            # connecting islands, with increasing costs
            return 10000000 + (i-n)*1024
elif mode == 'normal':
    def edge(i):
        return random.sample(node_indexes, 2)

    def weight(i):
        return random.randint(5, 10000000)
    assert m != -1, "You must set m here"
else:
    assert False, "invalid mode"

start_positions = random.sample(node_indexes, l)
edges = {frozenset(edge(i)): weight(i) for i in range(m)}
m = len(edges)
print("{} {} {}".format(n,l,m))
print('\n'.join(map(str, start_positions)))
for ((v1, v2), w) in edges.items():
    print(v1, v2, w)

