#!/usr/bin/env python2
def encode(C, K, N, X):
    encoding = [[] for i in range(4)]
    for i in range(N):
        sub = X[i*3:i*3+3]
        encoding[0].append(sub[0])
        encoding[1].append(sub[1])
        encoding[2].append(sub[2])
        encoding[3].append(chr(ord(sub[0]) ^ ord(sub[1]) ^ ord(sub[2])))
    encoding = [''.join(x) for x in encoding]
    return encoding

def decode(C, K, N, Y, I):
    ret = []
    for i in range(N):
        x = 0
        add = ['\0' for _ in range(3)]
        for j in range(3):
            if I[j] < 3:
                add[I[j]] = Y[j][i]
            x ^= ord(Y[j][i])

        for j in range(3):
            if add[j] == '\0':
                add[j] = chr(x)
        ret.append(''.join(add))
    return ''.join(ret)
