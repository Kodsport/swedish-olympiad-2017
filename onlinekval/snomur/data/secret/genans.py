T, N, W = [int(x) for x in input().split()]
blocks = [int(x) for x in input().split()]
print(int(2 * sum(blocks) / W + 1))
