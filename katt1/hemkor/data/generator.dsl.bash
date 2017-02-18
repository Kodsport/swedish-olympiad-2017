#!/bin/bash

PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh

setup_dirs
use_solution simon.cpp
compile generator_all.py

samplegroup
sample 1
sample 2

group small 25
tc small-1 generator_all n=100 m=100 mode=samep
tc small-2 generator_all n=100 m=100 mode=samev
tc small-3 generator_all n=100 m=100
tc small-4 generator_all n=100 m=100 mono=1

group samep 25
tc samep-1 generator_all n=5000 m=100000 mode=samep

group samev 25
tc samev-1 generator_all n=5000 m=100000 mode=samev

group large 25
include_group small
include_group samep
include_group samev
tc large-1 generator_all n=5000 m=100000
tc large-2 generator_all n=5000 m=100000 mono=1

generate_grader
cleanup_programs
