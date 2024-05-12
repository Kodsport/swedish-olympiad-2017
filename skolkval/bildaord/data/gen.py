#!/usr/bin/env python3

import sys
import random


def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default


random.seed(int(cmdlinearg('seed', sys.argv[-1])))

#testcases:
#60 poäng: n<=9 slag.
#40 poäng: inga ytterligare begränsningar

n = int(cmdlinearg("n",random.randint(2,15)))
k = int(cmdlinearg("k",random.randint(1,n)))

even = int(cmdlinearg("even", 0))

print(n,k)

chars = [chr(x) for x in range(65,65+n)]

chars = random.sample(chars,k)

for ch in chars:
    if random.randint(0,1):
        out = [ch, "@"]
        
        pos = random.sample([*range(1,n+1)],random.randint(1,n))
        
        if even:
            pos = random.sample([*range(1,n+1)], even)

        for p in pos:
            out.append("0"*(p < 10) + str(p))
            if pos[-1] != p:
                out.append(",")
    else:
        out = [ch, ":"]
        
        chs = random.sample([chr(x) for x in range(65,65+n)],random.randint(1,n))

        if even:
            chs = random.sample([chr(x) for x in range(65,65+n)], even)

        for c in chs:
            if c == ch:
                continue
            out.append(c)
        
    print("".join(out))
        


