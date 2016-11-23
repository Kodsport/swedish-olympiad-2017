#!/usr/bin/env python
import sys


def are_unique(nums):
    return len(nums) == len(set(nums))

data = []

for line in sys.stdin:
    if line.strip() != "":
        data.append(line.strip())

assert len(data) == 2

N, K = map(int, data[0].split())
assert 1 <= N <= 15
assert K < N
assert K == len(data) - 1

for i in range(1, K+1):
    line = map(int, data[i].split())
    form = line[0]
    pos = int(line[1])
    num_nums = int(line[2])
    nums = map(int, line[3:])
    assert form in 'ab'
    assert 1 <= pos <= N
    assert len(nums) == num_nums
    assert pos not in set(nums)
    assert are_unique(nums)

sys.exit(42)
