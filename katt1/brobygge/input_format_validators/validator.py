#!/usr/bin/env python3
import sys

N = int(input())
G = [[] for i in range(N)]
for i in range(N - 1):
    a, b, l = map(int, input().split())
    G[a].append(b)
    G[b].append(a)

seen = [False] * N
def dfs(at):
    if seen[at]: return
    seen[at] = True
    for child in G[at]:
        dfs(child)
dfs(0)
assert False not in seen

E = int(input())
for i in range(E):
    a, b, l = map(int, input().split())
    assert a not in G[b]
    assert b not in G[a]
    G[a].append(b)
    G[b].append(a)

Q = int(input())
for i in range(Q):
    a, b = map(int, input().split())
    assert a != b

sys.exit(42)
