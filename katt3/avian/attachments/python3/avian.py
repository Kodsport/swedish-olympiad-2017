#!/usr/bin/env python2
def encode(C, K, N, X):
    return ['0'*N for i in range(K)]

def decode(C, K, N, Y, I):
    return '0' * (C*N)
