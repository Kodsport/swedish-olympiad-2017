#!/usr/bin/env python3
from collections import defaultdict
import sys

N, W, H = map(int, input().split())
blocks = map(int, input().split())

left = defaultdict(int)
for block in blocks: left[block] += 1

for i in range(H):
    line = list(map(int, input().split()))
    B = line[0]
    lastpos = -1e9
    for j in range(0, B):
        pos = line[2 * j + 1]
        le = line[2 * j + 2]
        assert left[le] > 0
        left[le] -= 1
        assert pos > lastpos
        lastpos = pos

sys.exit(42)
