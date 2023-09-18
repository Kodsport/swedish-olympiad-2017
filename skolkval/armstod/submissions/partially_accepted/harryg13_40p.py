#!/usr/bin/env python3

n=int(input())

s=[*input()]

s=s[1:]+s[:1]

def calculate(res,lBlock,rBlock):
    for i in range(n-2,-1,-1):
        if s[i] in "HB" and lBlock[i+1]:
            continue
        if s[i] in "BV" and rBlock[i-1]:
            continue

        if s[i] ==  "A" and lBlock[i+1]:
            if rBlock[i-1]:
                continue
            res[i]=1
            lBlock[i]=1
            continue
        elif s[i]=="A":
            res[i]=1
            rBlock[i]=1
            continue

        res[i]=1

        if s[i] in "HB":
            rBlock[i]=1
        if s[i] in "VB":
            lBlock[i]=1

    return sum(res)

res=[0]*n
lBlock=[0]*n
rBlock=[0]*n
res[-1]=1
print(calculate(res,lBlock,rBlock))
