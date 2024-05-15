#!/usr/bin/env python3
import sys

N, K = map(int, input().split())
S = input().strip()
assert len(S) == N
for c in S:
    assert 0 <= ord(c) - ord('a') < K

for i in range(K):
    assert chr(ord('a') + i) in S

sys.exit(42)
