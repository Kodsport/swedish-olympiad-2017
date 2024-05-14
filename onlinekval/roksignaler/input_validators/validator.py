#!/usr/bin/env python3
import sys
import string
import sys

letters_to_ascii = {}
letters_to_ascii['A'] = '.-'
letters_to_ascii['B'] = '-...'
letters_to_ascii['C'] = '-.-.'
letters_to_ascii['D'] = '-..'
letters_to_ascii['E'] = '.'
letters_to_ascii['F'] = '..-.'
letters_to_ascii['G'] = '--.'
letters_to_ascii['H'] = '....'
letters_to_ascii['I'] = '..'
letters_to_ascii['J'] = '.---'
letters_to_ascii['K'] = '-.-'
letters_to_ascii['L'] = '.-..'
letters_to_ascii['M'] = '--'
letters_to_ascii['N'] = '-.'
letters_to_ascii['O'] = '---'
letters_to_ascii['P'] = '.--.'
letters_to_ascii['Q'] = '--.-'
letters_to_ascii['R'] = '.-.'
letters_to_ascii['S'] = '...'
letters_to_ascii['T'] = '-'
letters_to_ascii['U'] = '..-'
letters_to_ascii['V'] = '...-'
letters_to_ascii['W'] = '.--'
letters_to_ascii['X'] = '-..-'
letters_to_ascii['Y'] = '-.--'
letters_to_ascii['Z'] = '--..'

for letter in string.ascii_uppercase:
    line = input().split()
    assert len(line) > 0
    assert line[0] == letter
    assert line[1] == letters_to_ascii[letter]

line = input().split()
assert len(line) == 2
ones = set(map(int, line))
assert len(line) == len(ones)

line = input().split()
assert len(line) == 3
zeroes = set(map(int, line))
assert len(line) == len(zeroes)    


line = input().split()
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