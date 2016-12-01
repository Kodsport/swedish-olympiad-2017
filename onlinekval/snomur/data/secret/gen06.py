import random

T = 6
N = 100000
W = 100000
print("{} {} {}".format(T, N, W))
random.seed(T)


blocks = []

for i in range(N):
    blocks.append(i+1)

random.shuffle(blocks)
assert len(blocks) == N
print(" ".join(str(x) for x in blocks))

