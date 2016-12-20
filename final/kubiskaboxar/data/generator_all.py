#!/usr/bin/python3

import sys
import random


# This requires Python 3.5... ehhhhh
import importlib.util
spec = importlib.util.spec_from_file_location("arash_100", "../submissions/accepted/arash_100.py")
arash_100 = importlib.util.module_from_spec(spec)
spec.loader.exec_module(arash_100)

def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    return None  # This is ok for this task

def create_random_box(max_l):
    return arash_100.Box(
        random.randint(5, max_l),
        random.choice('RGB'),
        )

def make_boxes(n, max_l, enforce_rgb):
    while True:
        boxes = [create_random_box(max_l=max_l) for _i in range(n)]
        solutions = arash_100.solve(boxes)
        if enforce_rgb and str(solutions[0][1]) != 'RGB':
            continue
        if solutions[0][0] >= solutions[1][0]:
            assert solutions[0][0] == solutions[1][0]
            continue
        return boxes

def main():
    random.seed(int(sys.argv[-1]))
    n, max_l = (int(cmdlinearg(name)) for name in ['n', 'max_l'])
    enforce_rgb = cmdlinearg('enforce_rgb')
    assert enforce_rgb is None or enforce_rgb == 'yes'
    boxes = make_boxes(n=n, max_l=max_l, enforce_rgb=enforce_rgb)
    print(n)
    for box in boxes:
        print(box.length, box.color)


if __name__ == "__main__":
    main()
