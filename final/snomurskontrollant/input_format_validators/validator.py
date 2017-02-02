#!/usr/bin/env python3
from collections import defaultdict
import sys

W, H = map(int, input().split())

for i in range(H):
    line = list(map(int, input().split()))
    B = line[0]
    lastpos = -1e9
    for j in range(0, B):
        pos = line[2 * j + 1]
        le = line[2 * j + 2]
        assert pos > lastpos
        lastpos = pos

sys.exit(42)
