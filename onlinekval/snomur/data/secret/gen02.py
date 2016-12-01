import random

T = 2
N = 75
W = 11
print("{} {} {}".format(T, N, W))
random.seed(T)


blocks = []

sizes = [3, 4, 5]
for i in range(N):
    blocks.append(random.choice(sizes))

random.shuffle(blocks)
assert len(blocks) == N
print(" ".join(str(x) for x in blocks))
