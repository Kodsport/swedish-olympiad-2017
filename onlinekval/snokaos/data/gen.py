import sys
from random import randint

def gen(n=2000, m=100000, s=-1, p=-1):
	if s == -1:
		s = randint(0, n-1)
	if p == -1:
		p = randint(0, s)

	print(n, m, s, p)

	for i in range(m):
		a = b = randint(1, n)
		while b == a:
			b = randint(1, n)
		print(a, b)

	numsleft = list(range(1, n))

	while s > 0:
		i = randint(0, len(numsleft)-1)
		print(numsleft[i])
		numsleft = numsleft[:i]+numsleft[i+1:]
		s -= 1


if __name__ == "__main__":

	args = {key:int(value) for key, value in [tuple(x.split("=")) for x in sys.argv[1:]]}

	gen(**args)
