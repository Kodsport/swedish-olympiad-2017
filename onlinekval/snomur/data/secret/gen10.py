import random

T = 5
N = 100000
W = 1000
print("{} {} {}".format(T, N, W))
random.seed(T)


blocks = []

for i in range(N):
    blocks.append(random.choice([1, 2, 4, 8, 16, 32, 64, 128, 256, 512]))

random.shuffle(blocks)
assert len(blocks) == N
print(" ".join(str(x) for x in blocks))

