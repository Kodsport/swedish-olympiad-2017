#!/bin/bash
REQUIRE_SAMPLE_REUSE=0
PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh

use_solution js_100.cpp
compile generator_random.py
compile generator_exact.py
compile generator_off_by_one.py

samplegroup
sample 1
sample 2

group 1-single-limit 19
tc single-limit-01 generator_exact m=1
tc single-limit-02 generator_exact m=1
tc single-limit-03 generator_off_by_one m=1
tc single-limit-04 generator_off_by_one m=1
tc single-limit-05 generator_off_by_one m=1
tc single-limit-06 generator_off_by_one m=1

group 2-single 46
include_group 1-single-limit
tc single-01 generator_exact m=1 move
tc single-02 generator_exact m=1 move
tc single-03 generator_exact m=1 move
tc single-04 generator_exact m=1 move
tc single-05 generator_off_by_one m=1 move
tc single-06 generator_off_by_one m=1 move
tc single-07 generator_off_by_one m=1 move
tc single-08 generator_off_by_one m=1 move
tc single-09 generator_off_by_one m=1 move
tc single-10 generator_off_by_one m=1 move

group 3-large 35
include_group 2-single
tc large-01 generator_random
tc large-02 generator_random
tc large-03 generator_random
tc large-04 generator_random
tc large-05 generator_random
tc large-06 generator_random
tc large-07 generator_random
tc large-08 generator_random
tc large-09 generator_random
tc large-10 generator_random
tc large-11 generator_exact
tc large-12 generator_exact
tc large-13 generator_exact
tc large-14 generator_off_by_one
tc large-15 generator_off_by_one
tc large-16 generator_off_by_one
tc large-17 generator_off_by_one
tc large-18 generator_off_by_one
tc large-19 generator_off_by_one
tc large-20 generator_off_by_one