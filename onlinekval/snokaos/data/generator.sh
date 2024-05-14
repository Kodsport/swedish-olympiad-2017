#!/bin/bash
PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh

use_solution snokaos_On3.cpp
compile generator_random.py
compile generator_ai1.py

samplegroup
sample 1

group 1_p1 12
tc p1-1 generator_random p=1 m=100
tc p1-2 generator_random p=1 m=100
tc p1-3 generator_random p=1 m=100
tc p1-4 generator_random p=1 m=100
tc p1-5 generator_random p=1 m=100

group 2_s1 11
tc s1-1 generator_random s=10 m=100
tc s1-2 generator_random s=11 m=100
tc s1-3 generator_random s=12 m=100
tc s1-4 generator_random s=12 m=100
tc s1-5 generator_random s=12 m=100

group 3_ai1 10
tc ai1-1 generator_ai1 m=100
tc ai1-2 generator_ai1 m=100
tc ai1-3 generator_ai1 m=100
tc ai1-4 generator_ai1 m=100
tc ai1-5 generator_ai1 m=100

group 4_all 67
include_group 1_p1
include_group 2_s1
include_group 3_ai1
tc all-1 generator_random
tc all-2 generator_random
tc all-3 generator_random
tc all-4 generator_random
tc all-5 generator_random
tc all-6 generator_ai1 m=100000
tc all-7 generator_random
tc all-8 generator_random s=0 p=10
tc all-9 generator_random n=2
tc all-10 generator_random
tc 1
