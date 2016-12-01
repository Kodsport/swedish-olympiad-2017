import random

T = 9
N = 60
W = 15
print("{} {} {}".format(T, N, W))
random.seed(T)


blocks = []

for i in range(N):
    blocks.append(random.randint(1, 5))

random.shuffle(blocks)
assert len(blocks) == N
print(" ".join(str(x) for x in blocks))

