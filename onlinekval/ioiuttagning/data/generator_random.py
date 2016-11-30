import sys
import string
import random

random.seed(int(sys.argv[-1]))
mx = [random.randint(10, 700) for i in range(4)]
median = [random.randint(3, mx[i] - 5) for i in range(4)]
age = [7,8,9,1,2,3]
katts = 3

for arg in sys.argv:
    if arg.startswith("med="):
        median = [int(arg.split("=")[1])] * 4
    if arg.startswith("max="):
        mx = [int(arg.split("=")[1])] * 4
    if arg.startswith("age="):
        age = [int(arg.split("=")[1])]
    if arg.startswith("katt="):
        katts = int(arg.split("=")[1])

name = [random.choice(string.ascii_lowercase) for x in range(20)]

def genseq(med, mx, cnt, idx):
    nums = list(sorted([random.randint(0,mx[idx]) for r in range(cnt)]))
    nums[-1] = mx[idx]
    nums[19] = med[idx] -2
    nums[20] = med[idx] +2
    for k in range(19):
        if nums[k] > nums[19]: nums[k] = nums[19]
    for k in range(21, cnt):
        if nums[k] < nums[20]: nums[k] = nums[20]
    random.shuffle(nums)
    return nums

finals = genseq(median, mx, 40, 1)
thekatt = [genseq(median, mx, 40, 1+k) for k in range(katts)]
while len(thekatt) < 3:
    thekatt.append(thekatt[0])
katts = [[0]*3 for i in range(40)]
for i in range(3):
    for j in range(40):
        katts[j][i] = thekatt[i][j]

def genname():
    random.shuffle(name)
    return (''.join(name))

print(40)
for i in range(40):
    print("{} {} {} {}".format(genname(), str(random.choice(age)), str(finals[i]),
        ' '.join(str(x) for x in katts[i])))
