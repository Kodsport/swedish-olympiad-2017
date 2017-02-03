#! /usr/bin/python3
r"""
Arash AC(100) solution to glada_finlandare

Typ bara testad med:

    echo '1\n-10 100 150\n -40 0 100' | python3 submissions/accepted/arash_100.py

"""
import sys


def main():
    stdin_lines = []
    for line in sys.stdin:
        if line.strip() != "":
            stdin_lines.append(line.strip())

    _n = int(stdin_lines[0])
    a_tot, b_tot, c_tot = 0, 0, 0
    for line in stdin_lines[1:]:
        # TODO:
        # Inparsningen här är helt påhittad! Koden här skrevs innan själva
        # problem statement
        a, b, c = map(float, line.split())
        a_tot += a
        b_tot += b
        c_tot += c
    optimal_temperatur = -b_tot/(2*a_tot)
    total_gladje = (-b_tot * b_tot / (4*a_tot)) + c_tot
    print(total_gladje, optimal_temperatur)


if __name__ == '__main__':
    main()
