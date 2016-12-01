import re
import sys

def main():
    int_regex = "[1-9][0-9]*"
    line = sys.stdin.readline()
    assert re.match(int_regex + " " + int_regex, line)
    n,m = map(int, line.split())

    assert 1 <= n <= 100000
    assert 1 <= m <= 100000

    def read(n):
        line = sys.stdin.readline().split(' ')
        res = []
        assert len(line) == n
        for x in line:
            assert re.match(int_regex, x)
            y = int(x)
            res.append(y)
        for i in range(n-1):
            assert res[i] <= res[i+1]

    read(n)
    read(m)

    line = sys.stdin.readline()
    assert len(line) == 0

    sys.exit(42)

main()
