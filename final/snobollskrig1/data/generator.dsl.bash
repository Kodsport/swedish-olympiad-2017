#!/bin/bash

PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh

setup_dirs
use_solution simon.cpp
compile generator_all.py

samplegroup
sample 1
sample 2
sample 3
sample 4
sample 5

group line 8
tc line-1 generator_all n=1000 l=2 mode=line
tc line-2 generator_all n=2000 l=20 mode=line
tc line-3 generator_all n=4000 l=40 mode=line
tc line-4 generator_all n=100000 l=50 mode=line

group two 9
tc two-1 generator_all n=1000 l=2 m=1000 mode=random
tc two-2 generator_all n=2000 l=2 m=100000 mode=random
tc two-3 generator_all n=4000 l=2 m=100 mode=random
tc two-4 generator_all n=100000 l=2 m=100000 mode=random
tc two-5 generator_all n=100000 l=2 m=100000 mode=random
tc two-6 generator_all n=100000 l=2 m=100000 mode=random

group unweighted 24
tc unw-1 generator_all n=700 l=50 mode=islands unw=1
tc unw-2 generator_all n=70000 l=50 mode=islands unw=1
tc unw-3 generator_all n=1000 l=50 m=1000 mode=random unw=1
tc unw-4 generator_all n=70000 l=50 m=100000 mode=random unw=1

group nonodesmall 0
tc nonodesmall-1 generator_all n=50  l=10 mode=nonode small=1
tc nonodesmall-2 generator_all n=60  l=20 mode=nonode small=1
tc nonodesmall-3 generator_all n=80  l=30 mode=nonode small=1
tc nonodesmall-4 generator_all n=100 l=4 mode=nonode small=1
tc nonodesmall-5 generator_all n=200 l=50 mode=nonode small=1

group nonode 23
include_group nonodesmall
tc nonode-1 generator_all n=70000 l=50 mode=nonode
tc nonode-2 generator_all n=100000 l=7 m=1 mode=random

group small 29
include_group nonodesmall
tc small-1 generator_all n=2000 l=2 m=1000 mode=random small=1
tc small-2 generator_all n=2000 l=50 m=1000 mode=random small=1
tc small-3 generator_all n=2000 l=20 m=2000 mode=random small=1
tc small-4 generator_all n=700 l=50 m=2000 mode=random small=1
tc small-5 generator_all n=700 l=50 mode=islands small=1

group normal 7
include_group line
include_group two
include_group unweighted
include_group nonode
include_group small
tc normal-1 generator_all n=1000 l=2 m=100000 mode=random
tc normal-2 generator_all n=1000 l=50 m=100000 mode=random
tc normal-3 generator_all n=1000 l=20 m=5000 mode=random
tc normal-4 generator_all n=100000 l=50 m=100000 mode=random
tc normal-5 generator_all n=100000 l=4 m=100000 mode=random

generate_grader
cleanup_programs
