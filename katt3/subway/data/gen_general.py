#!/usr/bin/python3

import sys
import random
import math

def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert False

def randomstar(n):
    G = []
    for i in range(n - 1):
        G.append((i, n-1))
    return G

def randomline(n):
    G = []
    for i in range(n - 1):
        G.append((i, i+1))
    return G

def randomtree(n):
    edges = []
    for i in range(1, n):
        edges.append((i, random.randint(0,i-1)))
    return edges

def gen(n, a):
    if a == 'tree': return set(randomtree(n))
    if a == 'star': return set(randomstar(n))
    if a == 'line': return set(randomline(n))
    assert False

def ptree(G, n):
    x = list(range(n))
    random.shuffle(x)
    for a, b in G:
        if random.choice([True, False]):
            print("{} {}".format(x[a], x[b]))
        else:
            print("{} {}".format(x[b], x[a]))

def main():
    random.seed(int(sys.argv[-1]))
    n = int(cmdlinearg('n'))
    a = cmdlinearg('a')
    b = cmdlinearg('b')
    print(n)
    ptree(gen(n, a), n)
    ptree(gen(n, b), n)

if __name__ == "__main__":
    main()
