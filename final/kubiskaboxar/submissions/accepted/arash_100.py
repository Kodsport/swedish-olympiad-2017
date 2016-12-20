#! /usr/bin/python3
"""
Arash AC(100) solution to kubiska boxar
"""
#pylint: disable=missing-docstring, invalid-name
import sys
import itertools
import collections
from pprint import pprint  # pylint: disable=unused-import

Box = collections.namedtuple('Box', 'length color')

def main():
    stdin_lines = []
    for line in sys.stdin:
        if line.strip() != "":
            stdin_lines.append(line.strip())

    # Ignore parsing first line
    # parse step 2

    def parse_line(line):
        length_str, color = line.split()
        return Box(int(length_str), color)
    boxes = [parse_line(line) for line in stdin_lines[1:]]
    solutions = solve(boxes)
    assert len(solutions) == 6
    assert solutions[0][0] < solutions[1][0]  # Answer is unique
    score, rule = solutions[0]
    print("{} i {}".format(*rule[0:2]))
    print("{} i {}".format(*rule[1:3]))
    print(score)


def solve(boxes):
    rules = (''.join(tupl) for tupl in itertools.permutations('RGB'))
    return sorted((score_for_rule(boxes, rule), rule) for rule in rules)

def score_for_rule(boxes, rule):
    smallest = [box for box in boxes if box.color == rule[0]]
    medium = [box for box in boxes if box.color == rule[1]]
    biggest = [box for box in boxes if box.color == rule[2]]
    total_savings = savings(smallest, medium) + savings(medium, biggest)
    return len(boxes) - total_savings

def savings(smallers, biggers):
    smallers = sorted(smallers)
    biggers = sorted(biggers)
    j = 0
    for big in biggers:
        if j >= len(smallers):
            break
        small = smallers[j]
        if big > small:
            j += 1  # Make the smallest bigger
    return j


if __name__ == '__main__':
    main()
