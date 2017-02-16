#!/usr/bin/python3

import sys
import random
import math

def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert False

def mapping(query):
    n = int(math.floor(0.5 + math.sqrt(0.25 + 2*query)))
    m = int(query - n * (n - 1) // 2)
    return n, m

def rev(x, y):
    if x < y:
        x, y = y, x
    return x * (x - 1)//2 + y

def randomtree(n):
    edges = []
    for i in range(1, n):
        edges.append(rev(i, random.randint(0, i - 1)))
    return edges

def main():
    random.seed(int(sys.argv[-1]))
    n, e = (int(cmdlinearg(name)) for name in ['n', 'e'])
    print(n)
    edges = set(randomtree(n))
    for edge in edges:
        x, y = mapping(edge)
        print("{} {} {}".format(x, y, random.randint(1, 1000)))

    print(e)
    while True:
        nedges = random.sample(range(n * (n - 1) // 2), e)
        for edge in nedges:
            if edge in edges: break
        else:
            for edge in nedges:
                x, y = mapping(edge)
                print("{} {} {}".format(x, y, random.randint(1, 1000)))
            break


    q = min(n * (n - 1) // 2, 100000)
    print(q)
    queries = random.sample(range(n * (n - 1) // 2), q)
    for query in queries:
        print("{} {}".format(*mapping(query)))

if __name__ == "__main__":
    main()
