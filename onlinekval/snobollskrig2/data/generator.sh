#!/bin/bash
PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh

use_solution simon.cpp
compile generator_random.py # n m
compile generator_random2.py # n m
compile generator_mid.py # n m
compile generator_amisses.py # n m common reverse
compile generator_bstarts.py # n m
compile generator_bstarts2.py # n m

samplegroup
sample 1
sample 2

group 1_amisses 19
tc g1-1 generator_amisses 1000 900 0 0
tc g1-2 generator_amisses 800 1000 100 0
tc g1-3 generator_amisses 1 1000 1 0
tc g1-4 generator_amisses 1000 1 1 0

group 2_bstarts 23
tc g2-1 generator_bstarts 1000 1000
tc g2-2 generator_bstarts 1000 1000
tc g2-3 generator_bstarts 1 1000
tc g2-4 generator_amisses 1000 1000 0 0
tc g2-5 generator_amisses 100 1000 0 0

group 3_small 20
tc g3-1 generator_random 1000 1000
tc g3-2 generator_random 1000 1000
tc g3-3 generator_random 1 1000
tc g3-4 generator_random 1000 1
tc g3-5 generator_bstarts2 1000 1000
tc g3-6 generator_bstarts2 1000 1000
tc g3-7 generator_bstarts2 1 1000

group 4_large 38
include_group 1_amisses
include_group 2_bstarts
include_group 3_small
tc g4-1 generator_random 100000 100000
tc g4-2 generator_random 100000 100000
tc g4-3 generator_random2 100000 100000
tc g4-4 generator_mid 100000 100000
tc g4-5 generator_amisses 99000 100000 0 1
tc g4-6 generator_amisses 100000 90000 100 0
tc g4-7 generator_amisses 90000 100000 90000 0
tc 1
tc 2
