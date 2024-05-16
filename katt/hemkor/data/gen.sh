#!/bin/bash
REQUIRE_SAMPLE_REUSE=0
PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh

use_solution simon.cpp
compile generator_all.py

samplegroup
sample 1
sample 2

group 1-small 31
tc small-1 generator_all n=10 m=10 mode=samep
tc small-2 generator_all n=10 m=10 mode=samev
tc small-3 generator_all n=10 m=10
tc small-4 generator_all n=10 m=10 mono=1
tc small-5 generator_all n=100 m=100 mode=samep
tc small-6 generator_all n=100 m=100 mode=samev
tc small-7 generator_all n=100 m=100
tc small-8 generator_all n=100 m=100 mono=1

group 2-samep 19
tc samep-1 generator_all n=6 m=6 mode=samep
tc samep-2 generator_all n=10 m=10 mode=samep
tc samep-3 generator_all n=5000 m=100 mode=samep
tc samep-4 generator_all n=5000 m=100000 mode=samep
tc samep-5 generator_all n=5000 m=100000 mode=samep mono=1

group 3-samev 15
tc samev-1 generator_all n=6 m=6 mode=samev
tc samev-2 generator_all n=10 m=10 mode=samev
tc samev-3 generator_all n=5000 m=100 mode=samev
tc samev-4 generator_all n=5000 m=100000 mode=samev
tc samev-5 generator_all n=5000 m=100000 mode=samev mono=1

group 4-large 35
include_group 1-small
include_group 2-samep
include_group 3-samev
tc large-1 generator_all n=5000 m=100
tc large-2 generator_all n=5000 m=100000
tc large-3 generator_all n=5000 m=100000 mono=1