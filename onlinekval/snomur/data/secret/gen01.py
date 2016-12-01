import random

T = 1
N = 100000
W = 1000
print("{} {} {}".format(T, N, W))
random.seed(T)


blocks = []

for i in range(2*N//3):
    blocks.append(W)
for j in range(N - 2*N//3):
    blocks.append(1)

random.shuffle(blocks)
assert len(blocks) == N
print(" ".join(str(x) for x in blocks))
