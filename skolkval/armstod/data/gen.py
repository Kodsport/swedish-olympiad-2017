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

"""
  Grupp & Poängvärde & Gränser \\ \hline
  $1$    & $20$       &  $N=5$ och första bokstaven är \texttt{I}.\\ \hline 
  $2$    & $40$       &  $5\le N\le 15$ , vilka bokstäver som helst.\\ \hline 
  $3$    & $20$       &  $5\le N\le 30$ och första bokstaven är \texttt{I}.\\ \hline 
  $4$    & $20$       &  Inga ytterligare begränsningar. \\ \hline
"""

firstI=int(cmdlinearg("firstI",0))
maxN=int(cmdlinearg("maxN",30))

n = int(cmdlinearg("n",random.randint(5,maxN)))

V = int(cmdlinearg("V",1))
H = int(cmdlinearg("H",1))
A = int(cmdlinearg("A",1))
B = int(cmdlinearg("B",1))
I = int(cmdlinearg("I",1))


repeat = int(cmdlinearg("repeat",0))

frequency = [V,H,A,B,I]
letter = "VHABI"

pool = []
for i in range(5):
    for _ in range(frequency[i]):
        pool.append(letter[i])


"""
    \item \texttt{V}: vänster arm
    \item \texttt{H}: höger arm
    \item \texttt{A}: antingen vänster eller höger arm
    \item \texttt{B}: båda armarna
    \item \texttt{I}: ingen arm
"""
theString=[]
if firstI:
    theString.append("I")

if repeat:#creates a random repeating sequence
    random.shuffle(pool)
    subseq=random.sample(pool,repeat)
    theString+=subseq*15
    print(n)
    print("".join(theString[:n]))

else:

    while len(theString)<n:
        theString.append(random.choice(pool))


    print(n)
    print("".join(theString))


