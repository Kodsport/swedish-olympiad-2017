#!/usr/bin/env pypy

from __future__ import print_function
from __future__ import division
import subprocess
import random
import math
import sys
import string

method = sys.argv[1]
random.seed(int(sys.argv[-1]))

def exactly(n):
    return n

def rand(n, lo):
    return random.randint(n-lo, n)

def is_squarefree(n):
    i = 2
    while i*i <= n:
        if n % i == 0:
            n = n // i
            if n % i == 0:
                return False
        i += 1
    return True

def squarefree(n):
    while not is_squarefree(n):
        n -= 1
    return n

if method == 'exactly':
    print(exactly(eval(sys.argv[2])))
elif method == 'random':
    print(rand(eval(sys.argv[2]), eval(sys.argv[3])))
elif method == 'squarefree':
    print(squarefree(eval(sys.argv[2])))
else:
    assert False

