#!/bin/bash
PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh

setup_dirs
use_solution js_100.cpp
compile generator_periodic.py
compile generator_zero.py
compile generator_rnd.py

samplegroup
sample 1
sample 2

group small 8
tc small-01 generator_zero n=100 k=2
tc small-02 generator_rnd n=100 k=2
tc small-03 generator_rnd n=100 k=2
tc small-04 generator_periodic n=100 k=2
tc small-05 generator_periodic n=100 k=2

group bruteforce 10
include_group small
tc bruteforce-01 generator_zero n=100 k=7
tc bruteforce-02 generator_rnd n=100 k=7
tc bruteforce-03 generator_rnd n=100 k=7
tc bruteforce-04 generator_periodic n=100 k=7
tc bruteforce-05 generator_periodic n=100 k=7

group dp 28
include_group bruteforce
tc dp-01 generator_zero n=1000 k=10
tc dp-02 generator_zero n=1000 k=10
tc dp-03 generator_rnd n=1000 k=10
tc dp-04 generator_rnd n=1000 k=10
tc dp-05 generator_rnd n=1000 k=10
tc dp-06 generator_periodic n=1000 k=10
tc dp-07 generator_periodic n=1000 k=10
tc dp-08 generator_periodic n=1000 k=10

group precompute-bf 19
include_group bruteforce
tc precompute-bf-01 generator_zero n=1000000 k=10
tc precompute-bf-02 generator_zero n=1000000 k=10
tc precompute-bf-03 generator_rnd n=1000000 k=10
tc precompute-bf-04 generator_rnd n=1000000 k=10
tc precompute-bf-05 generator_rnd n=1000000 k=10
tc precompute-bf-06 generator_periodic n=1000000 k=10
tc precompute-bf-07 generator_periodic n=1000000 k=10
tc precompute-bf-08 generator_periodic n=1000000 k=10

group precompute-dp 35
include_group precompute-bf
tc precompute-dp-01 generator_zero n=1000000 k=18
tc precompute-dp-02 generator_zero n=1000000 k=18
tc precompute-dp-03 generator_zero n=1000000 k=18
tc precompute-dp-04 generator_rnd n=1000000 k=18
tc precompute-dp-05 generator_rnd n=1000000 k=18
tc precompute-dp-06 generator_rnd n=1000000 k=18
tc precompute-dp-07 generator_periodic n=1000000 k=18
tc precompute-dp-08 generator_periodic n=1000000 k=18
tc precompute-dp-09 generator_periodic n=1000000 k=18

generate_grader
generate_cms
cleanup_programs
