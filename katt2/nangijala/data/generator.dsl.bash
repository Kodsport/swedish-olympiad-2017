#!/bin/bash
PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh

setup_dirs
use_solution emanuel100.cpp
compile generator_pairs.py
compile generator_path.py
compile generator_cycle.py
compile generator_mixed.py
compile generator_tree.py

samplegroup
sample 1
sample 2
sample 3

group pairs 25
tc pairs-01 generator_pairs n=1000 m=23
tc pairs-02 generator_pairs n=100000 m=43212
tc pairs-03 generator_pairs n=100000 m=49997
tc pairs-04 generator_pairs n=1 m=0
tc pairs-04 generator_pairs n=100000 m=0

group small 25
tc small-01 generator_pairs n=15 m=5
tc small-02 generator_path n=15 m=13
tc small-03 generator_cycle n=15 m=12
tc small-04 generator_cycle n=15 m=15

group large 25
include_group pairs
include_group small
tc large-01 generator_path n=100000 m=99865
tc large-02 generator_cycle n=100000 m=100000
tc large-03 generator_cycle n=100000 m=99999
tc large-04 generator_mixed n=100000 m=50000 s=8000
tc large-05 generator_mixed n=100000 m=99999 s=50000

group tree 25
tc large-01 generator_tree n=100000
tc large-02 generator_tree n=100000
tc large-03 generator_tree n=100000
tc large-04 generator_tree n=10
tc large-04 generator_tree n=1

generate_grader
generate_cms
cleanup_programs
