#!/bin/bash
PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh

setup_dirs
use_solution arash_100.py
compile generator_random.py

# Not sure why I would want this right now.
# As I believe my hand-calculated values are more correct
# samplegroup
# sample 1
# sample 2
# sample 3
# sample 4
# sample 5

# TODO fill in with snobollskastning1 stuff

group nonormalize 23
tc g1-1 generator_random med=50 max=100
tc g1-2 generator_random med=50 max=100
tc g1-3 generator_random med=50 max=100
tc g1-4 generator_random med=50 max=100
tc g1-5 generator_random med=50 max=100

group firstyears 13
tc g2-1 generator_random age=1
tc g2-2 generator_random age=1
tc g2-3 generator_random age=1
tc g2-4 generator_random age=1
tc g1-5 generator_random age=1

group samekatt 31
tc g3-1 generator_random katt=1
tc g3-2 generator_random katt=1
tc g3-3 generator_random katt=1
tc g3-4 generator_random katt=1
tc g3-5 generator_random katt=1

group all 33
include_group p1
include_group s1
include_group ai1
tc g4-1 generator_random
tc g4-2 generator_random
tc g4-3 generator_random
tc g4-4 generator_random max=700 med=4
tc g4-5 generator_random max=700

generate_grader
cleanup_programs
