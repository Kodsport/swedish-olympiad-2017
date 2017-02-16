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

def main():
    random.seed(int(sys.argv[-1]))
    n, e = (int(cmdlinearg(name)) for name in ['n', 'e'])
    print(n)
    for i in range(n - 1):
        print("{} {} {}".format(i, i + 1, random.randint(1, 1000)))
    print(e)
    while True:
        edges = random.sample(range(n * (n - 1) // 2), e)
        for i in range(n - 1):
            if i * (i + 1) // 2 + i in edges:
                break
        else:
            for edge in edges:
                print("{} {} {}".format(*(mapping(edge) + (random.randint(1, 1000), ))))
            break


    q = min(n * (n - 1) // 2, 100000)
    print(q)
    queries = random.sample(range(n * (n - 1) // 2), q)
    for query in queries:
        print("{} {}".format(*mapping(query)))

if __name__ == "__main__":
    main()
