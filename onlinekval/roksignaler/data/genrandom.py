import sys
import string
import random

random.seed(int(sys.argv[-1]))

mx = [random.randint(10, 700) for i in range(4)]
median = [random.randint(3, mx[i] - 5) for i in range(4)]
age = [7,8,9,1,2,3]
katts = 3

fixedNums = False
noSpaces = False
numMax = 10
n = 100

for arg in sys.argv:
    if arg.startswith("numMax="):
        numMax = int(arg.split("=")[1])
    if arg.startswith("n="):
        n = int(arg.split("=")[1])
    if arg == ("nospaces"):
        noSpaces = True

s, p, t, b, m = random.sample(1, numMax)

if fixedNums:
    s = 2
    p = 1
    t = 1
    b = 2
    m = 3


dict = {}
dict['A'] = '.-'
dict['B'] = '-...'
dict['C'] = '-.-.'
dict['D'] = '-..'
dict['E'] = '.'
dict['F'] = '..-.'
dict['G'] = '--.'
dict['H'] = '....'
dict['I'] = '..'
dict['J'] = '.---'
dict['K'] = '-.-'
dict['L'] = '.-..'
dict['M'] = '--'
dict['N'] = '-.'
dict['O'] = '---'
dict['P'] = '.--.'
dict['Q'] = '--.-'
dict['R'] = '.-.'
dict['S'] = '...'
dict['T'] = '-'
dict['U'] = '..-'
dict['V'] = '...-'
dict['W'] = '.--'
dict['X'] = '-..-'
dict['Y'] = '-.--'
dict['Z'] = '--..'

outList = []
length = 0

def calcLength(morse):
    ret = 0
    for c in morse:
        if c == '-':
            ret += s
        else:
            ret += p
    return ret


while length < n:
    if not noSpaces and random.random() > 0.8 and length > 0 and outList[-1] != ' ':
        outList.append(' ')
        length += m
    else:
        outList.append(string.ascii_uppercase[random.randint(0, 25)])
        length += calcLength(morseToLetter[outList[-1]]) + b

outList = [:-1]

if len(outList) > 0 and outList[-1] == ' '
    outList = outList[:-1]

out = ''.join(outList)
if out == ' '
    out = 'E'

print(s),
print(p)

print(t),
print(b),
print(m)

print(n),
print(out)
