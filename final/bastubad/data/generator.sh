#!/bin/bash

PPATH=$(realpath ..)

. ../../testdata_tools/gen.sh

use_solution sol.cpp

compile generator_random.py

samplegroup
sample 1
sample 2
sample 3

group same-endpoint 21
tc se-01 generator_random n=10 t=0.2 cap=8000 seed=1
tc se-02 generator_random n=10 t=0.8 cap=10000 seed=2
tc se-03 generator_random n=1000 t=0.2 cap=10000 seed=3
tc se-04 generator_random n=1000 t=0.8 cap=8000 seed=4
tc_manual ../manual_testdata/linear.in
# (centers left of x = 0)
tc_manual ../manual_testdata/outside-convex.in
tc_manual ../manual_testdata/outside-concave.in

group convex 29
tc 1
tc 2
# (half of these are optimized at t = 0, due to the random choice of 'midp')
tc convex-01 generator_random n=10 seed=1234 t=convex
tc convex-02 generator_random n=10 seed=1237 t=convex
tc convex-03 generator_random n=1000 seed=1230 t=convex
tc convex-04 generator_random n=1000 seed=1231 t=convex
tc_manual ../manual_testdata/outside-convex.in

group concave 38
tc 3
# (the one with seed=1004 is optimized at a non-cutoff point.
# this is harder to trigger with large n, so we don't bother.)
tc concave-01 generator_random n=10 t=concave
tc concave-02 generator_random n=10 t=concave
tc concave-03 generator_random n=10 t=concave
tc concave-04 generator_random n=10 seed=1004 t=concave
tc concave-05 generator_random n=1000 t=concave
tc concave-06 generator_random n=1000 t=concave
tc_manual ../manual_testdata/outside-concave.in

group large 12
include_group samplegroup
include_group same-endpoint
include_group convex
include_group concave
tc large-01 generator_random n=100000 t=concave
tc large-02 generator_random n=100000 t=convex
tc large-03 generator_random n=100000 t=0.2
tc large-04 generator_random n=100000 t=0.8
tc large-05 generator_random n=10 t=0.2 seed=1032
tc large-06 generator_random n=10 t=0.2 seed=1055

