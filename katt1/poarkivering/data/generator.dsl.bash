#!/bin/bash

PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh

setup_dirs
use_solution simon.cpp
compile generator_all.py

samplegroup
sample 1
sample 2

group dsame 11
tc constant-1 generator_all n=1 mode=constant a=2 b=3
tc constant-2 generator_all n=100 mode=constant a=2 b=3
tc constant-3 generator_all n=100 mode=constant a=3 b=2
tc dsame-1 generator_all n=10 mode=dsame
tc dsame-2 generator_all n=100 mode=dsame
tc dsame-3 generator_all n=100 mode=dsame
tc dsame-4 generator_all n=100 mode=dsame

group ssame 27
tc constant-1
tc constant-2
tc constant-3
tc ssame-1 generator_all n=10 mode=ssame
tc ssame-2 generator_all n=100 mode=ssame
tc ssame-3 generator_all n=100 mode=ssame
tc ssame-4 generator_all n=100 mode=ssame
tc ssame-5 generator_all n=100 mode=ssame

group normal 48
include_group dsame
include_group ssame
tc normal-1 generator_all n=10
tc normal-2 generator_all n=100
tc normal-3 generator_all n=100
tc normal-4 generator_all n=100

group hard 14
include_group normal
tc hard-1 generator_all n=11 s=0
tc hard-2 generator_all n=99 s=0
tc hard-3 generator_all n=99 s=0
tc hard-4 generator_all n=99 s=0
tc hard-5 generator_all n=99 mode=ssame s=0
tc hard-6 generator_all n=99 mode=dsame s=0

generate_grader
generate_cms
cleanup_programs
