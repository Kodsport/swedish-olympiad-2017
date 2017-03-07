#!/usr/bin/env python3
import sys
sys.setrecursionlimit(300000)

N = int(input())
G = [[] for i in range(N)]
for i in range(N - 1):
    a, b = map(int, input().split())
    assert a != b
    G[a].append(b)
    G[b].append(a)

G2 = [[] for i in range(N)]
for i in range(N - 1):
    a, b = map(int, input().split())
    assert a != b
    G2[a].append(b)
    G2[b].append(a)

def is_connected(G):
    seen = [False] * N
    def dfs(at):
        if seen[at]: return
        seen[at] = True
        for child in G[at]:
            dfs(child)
    dfs(0)
    assert False not in seen

is_connected(G)
is_connected(G2)

sys.exit(42)
