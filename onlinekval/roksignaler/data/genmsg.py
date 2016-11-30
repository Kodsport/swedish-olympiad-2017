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
dict[' '] = 'M'

s, p = map(int, input().split())
t, b, m = map(int, input().split())
msg = input()

morseList = []
for c in msg:
    morseList.append(dict[c])

outList = []
for i, morse in enumerate(morseList):
    cloud = ''
    if morse == 'M':
        cloud = '0' * m
    else:
        for j, c in enumerate(morse):
            if c == '-':
                cloud += '1' * s
            elif c == '.':
                cloud += '1' * p
            elif c == 'M':
                cloud = '0' * m
            if j != len(morse) - 1:
                cloud += '0' * t
        if i != len(morseList) - 1 and (i != 0 or morseList[i-1] != 'M') and morseList[i + 1] != 'M':
            cloud += '0' * b
    outList.append(cloud)

out = ''.join(outList)
n = len(out)

print("{} {}".format(s, p))
print("{} {} {}".format(t, b, m))

print("{} {}".format(n, out))
