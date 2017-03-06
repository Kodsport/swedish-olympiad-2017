#!/usr/bin/env python2

import sys

from avian import encode, decode

def main():
    C, K, N = map(int, sys.stdin.readline().split())
    X = sys.stdin.readline()
    I = list(map(int, sys.stdin.readline().split()))

    encoded = encode(C, K, N, X)
    if len(encoded) != K:
        sys.stderr.write("Encoder gave {} strings, expected {}\n".format(len(encoded), K))
        sys.exit(0)

    for s in encoded:
        if len(s) != N:
            sys.stderr.write("Encoder gave string of length {}, expected {}\n".format(len(s), N))
            sys.exit(0)

            for c in s:
                if not c in ['0', '1']:
                    sys.stderr.write("Encoder gave string containing {}, expected either 0 or 1\n", c)
                    sys.exit(0)

    subset = []
    for i in range(C):
        subset.append(encoded[I[i]])

    decoded = decode(C, K, N, subset, I);
    sys.stdout.write(decoded + "\n")

if __name__ == "__main__":
    main()
