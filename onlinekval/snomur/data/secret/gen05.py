import random

T = 5
N = 100000
W = 1000
print("{} {} {}".format(T, N, W))
random.seed(T)


blocks = []

for i in range(N):
    blocks.append(random.randint(1, W))

random.shuffle(blocks)
assert len(blocks) == N
print(" ".join(str(x) for x in blocks))

