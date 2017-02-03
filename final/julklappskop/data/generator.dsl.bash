#!/bin/bash

PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh

setup_dirs
use_solution sol_matching.cpp
compile generator_random.py

samplegroup
sample 1

group quadratic 0
tc quad-01 generator_random n=2 k=2 m=5000
tc quad-02 generator_random n=2 k=2 m=5000
tc quad-03 generator_random n=2 k=2 m=5000
tc quad-04 generator_random n=2 k=3 m=5000
tc quad-05 generator_random n=2 k=10 m=5000
tc quad-06 generator_random n=2 k=5000 m=5000

group linear 34
include_group quadratic
tc linear-01 generator_random n=2 k=2 m=100000
tc linear-02 generator_random n=2 k=2 m=100000
tc linear-03 generator_random n=2 k=10 m=100000
tc linear-04 generator_random n=2 k=100000 m=100000

group nifty 34
include_group linear
tc nifty-01 generator_random n=4 k=4 m=100000
tc nifty-02 generator_random n=8 k=9 m=100000
tc nifty-03 generator_random n=8 k=30 m=100000
tc nifty-04 generator_random n=4 k=100000 m=100000
tc nifty-05 generator_random n=8 k=100000 m=100000

group dp 35
tc dp-01 generator_random n=2 k=2 m=200
tc dp-02 generator_random n=2 k=2 m=200
tc dp-03 generator_random n=2 k=3 m=200
tc dp-04 generator_random n=8 k=200 m=200
tc dp-05 generator_random n=14 k=14 m=200
tc dp-06 generator_random n=14 k=19 m=200
tc dp-07 generator_random n=14 k=100 m=200

group large 35
include_group dp
include_group nifty
tc large-01 generator_random n=14 k=14 m=100000
tc large-02 generator_random n=13 k=19 m=100000
tc large-03 generator_random n=14 k=100 m=100000
tc large-04 generator_random n=14 k=100000 m=100000

generate_grader
cleanup_programs
