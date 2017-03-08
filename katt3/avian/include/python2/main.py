#!/usr/bin/env python2
import os
import sys

from avian import encode, decode

_USER_FAIL = 120;
_SECRET_KEY = "iunty23v7itdhugh3c";

def main():
    C, K, N = map(int, sys.stdin.readline().strip().split())
    X = sys.stdin.readline().strip()
    I = list(map(int, sys.stdin.readline().strip().split()))

    r, w = os.pipe()
    pid = os.fork()

    if pid == 0:
        os.close(r)
        w = os.fdopen(w, 'w')
        encoded = encode(C, K, N, X)
        if len(encoded) != K:
            sys.stderr.write("Encoder gave {} strings, expected {}\n".format(len(encoded), K))
            sys.exit(_USER_FAIL)

        for s in encoded:
            if len(s) != N:
                sys.stderr.write("Encoder gave string of length {}, expected {}\n".format(len(s), N))
                sys.exit(_USER_FAIL)

                for c in s:
                    if not c in ['0', '1']:
                        sys.stderr.write("Encoder gave string containing {}, expected either 0 or 1\n", c)
                        sys.exit(_USER_FAIL)

        for i in range(C):
            w.write(encoded[I[i]])
            w.write("\n")

        w.close()
    else:
        os.close(w)
        r = os.fdopen(r)
        pid, status = os.waitpid(pid, 0)
        if os.WIFSIGNALED(status): os.kill(pid, os.WTERMSIG(status))
        ex = os.WEXITSTATUS(status)
        if ex == _USER_FAIL: sys.exit(0);
        if ex != 0: sys.exit(ex);
        buf = r.read()
        subset = buf.strip().split('\n')
        decoded = decode(C, K, N, subset, I);
        sys.stdout.write(_SECRET_KEY + decoded + "\n")

if __name__ == "__main__":
    main()
