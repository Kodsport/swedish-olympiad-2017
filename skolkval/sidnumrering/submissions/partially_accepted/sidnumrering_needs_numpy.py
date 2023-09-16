#!/usr/bin/env python3
import sys
from numpy import *

def unit(k):
    v=zeros(10,'int64')
    v[k]=1
    return v

def base(n):
    v=zeros(10,'int64')
    for i in range(1,n+1,2):
        v[i]=1
    return v

def allupto(n,start):
    v=zeros(10,'int64')
    for i in range(start,n):
        v[i]=1
    return v
    
def numbersplit(n,k=None):
    if k==None:
        k=1
        while(n>k*10): k*=10
    return (n/k, k, n%k)

def a(n,k=None):
    if(n<=10 and (k==None or k==1)): return base(n)
    (fact,big,small)=numbersplit(n,k)   #  n=fact*big + small
    return fact*a(big)+ big/2*allupto(fact,0)  + ( ((small+1)/2)*unit(fact)+a(small,big/10) if small>0 else 0)

def s(n,k=None):
    if(n<=10): return base(n)
    (fact,big,small)=numbersplit(n,k)   #  n=fact*big + small
    return (fact-1)*a(big)+s(big)+big/2*allupto(fact,1) + ( ((small+1)/2)*unit(fact)+a(small,big/10) if small>0 else 0)

N=int(sys.stdin.readline())
print(" ".join([str(x) for x in s(N)]))
