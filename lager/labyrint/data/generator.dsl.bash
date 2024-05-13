#!/bin/bash

PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh

setup_dirs
use_solution david.cpp
compile generator_existing.py
compile generator_random.py

samplegroup
sample 1

group all 100
tc tiny-ex generator_existing n=6 m=6
tc small generator_existing n=10 m=7 dup=0
tc small-pad generator_existing n=10 m=7 padding=100
tc small-rand generator_random m=15
tc small-ex generator_existing n=10 m=4000 dup=0
tc medium-rand generator_random m=100
tc medium-ex generator_existing n=100 m=400 dup=0
tc large-ex generator_existing n=200 m=2000
tc huge generator_random m=100000 dup=0
tc huge-pad generator_random m=1 padding=200000

generate_grader
generate_cms
cleanup_programs

cp testdata.yaml secret/testdata.yaml # sum, not groups
