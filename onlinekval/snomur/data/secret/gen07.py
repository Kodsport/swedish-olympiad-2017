import random

T = 7
N = 100000
W = 50
print("{} {} {}".format(T, N, W))
random.seed(T)


blocks = []

for i in range(N):
    blocks.append(random.randint(5, 10))

random.shuffle(blocks)
assert len(blocks) == N
print(" ".join(str(x) for x in blocks))

