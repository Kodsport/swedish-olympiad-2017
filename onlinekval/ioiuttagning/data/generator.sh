#!/bin/bash
PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh

use_solution karl.py
compile generator_random.py

samplegroup
sample 1
sample 2

group 1_nonormalize 23
tc g1-1 generator_random med=50 max=100
tc g1-2 generator_random med=50 max=100
tc g1-3 generator_random med=50 max=100
tc g1-4 generator_random med=50 max=100
tc g1-5 generator_random med=50 max=100

group 2_firstyears 13
tc g2-1 generator_random age=1
tc g2-2 generator_random age=1
tc g2-3 generator_random age=1
tc g2-4 generator_random age=1
tc g2-5 generator_random age=1

group 3_samekatt 31
tc g3-1 generator_random katt=1
tc g3-2 generator_random katt=1
tc g3-3 generator_random katt=1
tc g3-4 generator_random katt=1
tc g3-5 generator_random katt=1

group 4_all 33
include_group 1_nonormalize
include_group 2_firstyears
include_group 3_samekatt
tc g4-1 generator_random
tc g4-2 generator_random
tc g4-3 generator_random
tc g4-4 generator_random max=700 med=4
tc g4-5 generator_random max=700
tc 1
tc 2
