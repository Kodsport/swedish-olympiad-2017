#!/usr/bin/env python3
from itertools import permutations

n,k = map(int,input().split())

rules = [input() for _ in range(k)]

chars = [chr(x) for x in range(65,65+n)]

cnt = 0

def check(perm):
    perm = list(perm)
    #print(perm)
    for rule in rules:
        if rule[1] == ":":
            ind = perm.index(rule[0])
            if ind == n-1:
                return 0
            if perm[ind+1] not in rule[2:]:
                return 0
        else:
            pos = set([*map(lambda x: int(x)-1,rule[2:].split(","))])
            ind = perm.index(rule[0])
            if ind not in pos:
                return 0
    
    return 1

for perm in permutations(chars):
    cnt += check(perm)

print(cnt)
