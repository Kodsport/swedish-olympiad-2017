import sys
import string
import sys

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

for letter in string.ascii_uppercase:
    line = raw_input().split()
    assert len(line) > 0
    assert line[0] == letter
    assert line[1] == dict[letter]

line = raw_input().split()
assert len(line) == 2
ones = set(map(int, line))
assert len(line) == len(ones)

line = raw_input().split()
assert len(line) == 3
zeroes = set(map(int, line))
assert len(line) == len(zeroes)    


line = raw_input().split()
assert len(line) == 2
n = int(line[0])
code = line[1]

assert len(code) == n

assert code[0] == '1'
assert code[-1] == '1'

cur = code[0]
count = 0

for c in code:
    assert c == '0' or c == '1'
    if c != cur:
        if cur == '0':
            assert count in zeroes
        else:
            assert count in ones

        cur = c
        count = 0
    
    count += 1

# All good
sys.exit(42)