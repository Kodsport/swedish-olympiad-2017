import random

T = 8
N = 100
W = 50000
print("{} {} {}".format(T, N, W))
random.seed(T)


blocks = []

for i in range(N):
    blocks.append(random.randint(400, 600))

random.shuffle(blocks)
assert len(blocks) == N
print(" ".join(str(x) for x in blocks))

