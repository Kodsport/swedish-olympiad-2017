#!/usr/bin/env python3
import sys

N, M = map(int, input().split())
deg = [0] * N
ed = [[] for _ in range(N)]
for i in range(M):
    a, b = map(int, input().split())
    deg[a] += 1
    deg[b] += 1
    ed[a].append(b)
    ed[b].append(a)

maxdeg = 0
for i in range(N):
    maxdeg = max(maxdeg, deg[i])

if maxdeg > 2:
    assert M == N-1
    seen = [False] * N
    st = [0]
    while st:
        x = st.pop()
        if seen[x]:
            continue
        seen[x] = True
        for y in ed[x]:
            st.append(y)
    assert seen == [True] * N

sys.exit(42)
