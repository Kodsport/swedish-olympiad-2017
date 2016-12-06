import re
import sys

int_regex = "(0|[1-9][0-9]*)"
intspace_regex = int_regex + "( " + int_regex+")*"
line_regex = "^" + intspace_regex + "$"

line = sys.stdin.readline()
assert re.match(line_regex, line)
vals=[int(x) for x in line.split()]
assert len(vals)==5
[x,a,y,b,n]=vals
assert 2 <= n <= 1000
assert 0 <= x <= 1000
assert 0 <= y <= 1000
assert 1 <= a <= 1000
assert 1 <= b <= 1000
line = sys.stdin.readline()
assert len(line) == 0
sys.exit(42)
