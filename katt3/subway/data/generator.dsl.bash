#!/bin/bash
PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh

setup_dirs
use_solution simon.cpp
compile gen_random.py
compile gen_line.py

samplegroup
sample 1
sample 2

group small 25
tc small-01 gen_general n=10
tc small-02 gen_general n=10
tc small-03 gen_general n=10
tc small-04 gen_general n=10
tc small-05 gen_general n=10
tc small-05 gen_general n=10
tc small-06 gen_general n=10

tc small-07 gen_line n=10
tc small-08 gen_line n=10
tc small-09 gen_line n=10
tc small-10 gen_line n=10

group mid 25
include_group small
tc mid-01 gen_general n=1000
tc mid-02 gen_general n=1000
tc mid-03 gen_general n=1000
tc mid-04 gen_general n=1000
tc mid-05 gen_general n=1000
tc mid-05 gen_general n=1000
tc mid-06 gen_general n=1000

tc mid-07 gen_line n=1000
tc mid-08 gen_line n=1000
tc mid-09 gen_line n=1000
tc mid-10 gen_line n=1000

group large 25
include_group mid
tc large-01 gen_general n=200000
tc large-02 gen_general n=200000
tc large-03 gen_general n=200000
tc large-04 gen_general n=200000
tc large-05 gen_general n=200000
tc large-05 gen_general n=200000
tc large-06 gen_general n=200000

tc large-07 gen_line n=200000
tc large-08 gen_line n=200000
tc large-09 gen_line n=200000
tc large-10 gen_line n=200000

generate_grader
generate_cms
cleanup_programs
