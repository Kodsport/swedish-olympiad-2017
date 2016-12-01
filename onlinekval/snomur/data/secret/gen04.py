import random

T = 4
N = 1000
W = 1000
print("{} {} {}".format(T, N, W))
random.seed(T)


blocks = []

for i in range(400):
    blocks.append(random.randint(W/5-50, W/5+50))
for i in range(600):
    blocks.append(random.randint(4, 6))

random.shuffle(blocks)
assert len(blocks) == N
print(" ".join(str(x) for x in blocks))

