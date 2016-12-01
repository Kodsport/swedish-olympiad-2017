#!/usr/bin/python3

import sys
import random

def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    return None  # This is ok for this task

def main():
    random.seed(int(sys.argv[-1]))
    n, l, m = (int(cmdlinearg(c)) for c in 'nlm')
    assert n
    assert l
    mode = cmdlinearg('mode')
    node_indexes = list(range(n))

    if mode == 'linje':
        assert not m
        m = n-1
        def edge(i):
            return (i, i+1)
        def weight(i):
            return random.randint(5, 100)
    elif mode == 'inge_nodkrig':
        assert not m
        ISLAND_SIZE = 10
        m = 2*n
        def edge(i):
            if i < n:
                # within an island
                j = n - (n%ISLAND_SIZE)
                return random.sample(range(j, j + ISLAND_SIZE), 2)
            else:
                # connecting islands
                return random.sample(node_indexes, 2)
        def weight(i):
            if i < n:
                # within an island
                return 1 << (n%ISLAND_SIZE)
            else:
                # connecting islands
                return random.randint(10000000, 20000000)
        pass
    elif mode == 'normal':
        def edge(i):
            return random.sample(node_indexes, 2)
        def weight(i):
            return random.randint(5, 10000000)
        assert m, "You must set m here"
    else:
        assert False, "mode is not valid value"
    start_positions = random.sample(node_indexes, l)

    # TODO

if __name__ == "__main__":
    main()
