#!/usr/bin/env python3

n = int(input())

slag = [*map(int,input().split())]

parTot = slagTot = 0

for i in range(n):
    parTot += 2+(i%2)
    slagTot += slag[i]

print(slagTot-parTot)
