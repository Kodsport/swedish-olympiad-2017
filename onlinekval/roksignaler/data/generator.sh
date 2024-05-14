#!/bin/bash
PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh

use_solution karl_ac.py
compile generator_random.sh

samplegroup
sample 1
sample 2

group 1_fixednums 19
tc g1-1 generator_random fixedNums noSpaces n=100
tc g1-2 generator_random fixedNums noSpaces n=100
tc g1-3 generator_random fixedNums noSpaces n=100
tc g1-4 generator_random fixedNums noSpaces n=100
tc g1-5 generator_random fixedNums noSpaces n=100

group 2_nospaces 39
tc g2-1 generator_random noSpaces numMax=10 n=1000
tc g2-2 generator_random noSpaces numMax=10 n=1000
tc g2-3 generator_random noSpaces numMax=10 n=1000
tc g2-4 generator_random noSpaces fixedNums n=1000
tc g2-5 generator_random noSpaces fixedNums n=1000


group 3_small 25
tc g3-1 generator_random numMax=100 n=1000
tc g3-2 generator_random numMax=100 n=1000
tc g3-3 generator_random numMax=100 n=1000
tc g3-4 generator_random numMax=100 n=1000
tc g3-5 generator_random numMax=10 n=1000
tc g3-6 generator_random fixedNums n=1000

group 4_all 17
include_group 1_fixednums
include_group 2_nospaces
include_group 3_small
tc g4-1 generator_random numMax=1000 n=100000
tc g4-2 generator_random numMax=1000 n=100000
tc g4-3 generator_random numMax=100 n=100000
tc g4-4 generator_random numMax=100 n=100000
tc g4-5 generator_random numMax=10 n=100000
tc g4-6 generator_random numMax=10 n=100000
tc g4-7 generator_random fixedNums n=100000
tc g4-8 generator_random fixedNums n=100000
tc 1
tc 2
