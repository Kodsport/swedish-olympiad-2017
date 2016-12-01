import random

T = 3
N = 5000
W = 100
print("{} {} {}".format(T, N, W))
random.seed(T)


blocks = []

for i in range(500):
    blocks.append(W)
for i in range(3000):
    blocks.append(random.randint(1, 30))
for i in range(1500):
    blocks.append(random.randint(31, W))

random.shuffle(blocks)
assert len(blocks) == N
print(" ".join(str(x) for x in blocks))
