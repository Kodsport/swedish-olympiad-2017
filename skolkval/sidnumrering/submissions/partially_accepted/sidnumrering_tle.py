#!/usr/bin/env python3
import sys
N=int(sys.stdin.readline())
s=list("".join([str(x) for x in range(1,N+1,2)]))
print(" ".join([str(s.count(str(i))) for i in range(10)]))
