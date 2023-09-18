#!/usr/bin/env python3

n=int(input())

s=[*input()]

o=0

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
o=max(o,calculate(res,lBlock,rBlock))

#om sista är A, anta först att den blockar vänster, sedan höger
if s[-1]=="A":
    res=[0]*n
    lBlock=[0]*n
    rBlock=[0]*n
    res[-1]=1
    lBlock[-1]=1
    o=max(o,calculate(res,lBlock,rBlock))

res=[0]*n
lBlock=[0]*n
rBlock=[0]*n
res[-1]=1
if s[-1] in "BHA": rBlock[-1]=1
if s[-1] in "VB": lBlock[-1]=1
o=max(o,calculate(res,lBlock,rBlock))

print(o)
