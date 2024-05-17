#!/bin/bash
PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh

ulimit -s unlimited
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

group 1-pairs 11
tc 1
tc pairs-01 generator_pairs n=1000 m=23
tc pairs-02 generator_pairs n=100000 m=43212
tc pairs-03 generator_pairs n=100000 m=49997
tc pairs-04 generator_pairs n=1 m=0
tc pairs-05 generator_pairs n=100000 m=0

group 2-large 36
include_group 1-pairs
tc 2
tc large-01 generator_path n=100000 m=99865
tc large-02 generator_cycle n=100000 m=100000
tc large-03 generator_cycle n=100000 m=99999
tc large-04 generator_mixed n=100000 m=50000 s=8000
tc large-05 generator_mixed n=100000 m=99999 s=50000
tc large-06 generator_mixed n=100000 m=49999 s=3

group 3-small_tree 26
tc 3
tc small_tree-01 generator_tree n=10
tc small_tree-02 generator_tree n=10
tc small_tree-03 generator_tree n=10
tc small_tree-04 generator_tree n=10
tc small_tree-05 generator_tree n=10
tc small_tree-06 generator_tree n=10
tc small_tree-07 generator_tree n=10
tc small_tree-08 generator_tree n=10 seed=15
tc small_tree-09 generator_tree n=10 seed=52
tc small_tree-10 generator_tree n=10 seed=72
tc small_tree-11 generator_tree n=1

group 4-tree 27
include_group 3-small_tree
tc tree-01 generator_tree n=100000
tc tree-02 generator_tree n=100000
tc tree-03 generator_tree n=100000

