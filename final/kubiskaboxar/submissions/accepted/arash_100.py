#! /usr/bin/python3
"""
Arash AC(100) solution to kubiska boxar
"""
#pylint: disable=missing-docstring, invalid-name
import sys
from pprint import pprint  # pylint: disable=unused-import


def main():
    stdin_lines = []
    for line in sys.stdin:
        if line.strip() != "":
            stdin_lines.append(line.strip())

    # parse step 1
    n = int(stdin_lines[0])
    # parse step 2
    print("TODO", n)


if __name__ == '__main__':
    main()
