#!/usr/bin/env python3 
N, M = [int(x) for x in input().split()]
has = sum(x * 2**y for x, y in zip(map(int, input().split()), range(N)))
needs = sum(map(int, input().split()))
print("ja" if has >= needs else "no")
