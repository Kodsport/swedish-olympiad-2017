#!/usr/bin/python3

import sys
import random
import math

def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert False

def randomtree(n):
    edges = []
    for i in range(1, n):
        edges.append((i, random.randint(0, i - 1)))
    return edges

def randomline(n):
    x = list(range(n))
    random.shuffle(x)
    G = []
    for i in range(n - 1):
        G.append((x[i], x[i+1]))
    return G


def ptree(G):
    for a, b in G:
        print("{} {}".format(a, b))

def main():
    random.seed(int(sys.argv[-1]))
    n = int(cmdlinearg('n'))
    E1 = set(randomtree(n))
    E2 = set(randomline(n))
    print(n)
    ptree(E1)
    ptree(E2)

if __name__ == "__main__":
    main()
