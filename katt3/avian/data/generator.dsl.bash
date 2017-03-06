#!/bin/bash
PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh

setup_dirs
use_solution ../cheat.cpp
compile gen_random.py

group Subtask-1 33
for i in {0..15}
do
tc subtask1-`printf "%02d" $i` gen_random c=3 k=4
done

group Subtask-2 33
for i in {0..15}
do
tc subtask2-`printf "%02d" $i` gen_random c=2 k=4
done

group Subtask-3 34
for i in {0..15}
do
tc subtask3-`printf "%02d" $i` gen_random c=3 k=5
done

generate_grader
cleanup_programs
