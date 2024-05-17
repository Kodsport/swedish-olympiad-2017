#!/bin/bash

PPATH=$(realpath ..)

. ../../testdata_tools/gen.sh

use_solution sol.cpp

compile generator_random.py

samplegroup
sample 1
sample 2
sample 3

# (centers left of x = 0)
group 1-same-endpoint 21
limits mode="same" maxN=1000
tc se-01 generator_random n=10 t=0.2 cap=8000 seed=1
tc se-02 generator_random n=10 t=0.8 cap=10000 seed=2
tc se-03 generator_random n=1000 t=0.2 cap=10000 seed=3
tc se-04 generator_random n=1000 t=0.8 cap=8000 seed=4
tc_manual ../manual_testdata/linear.in
tc_manual ../manual_testdata/outside-convex.in
tc_manual ../manual_testdata/outside-concave.in

# (half of these are optimized at t = 0, due to the random choice of 'midp')
group 2-convex 29
limits mode="convex" maxN=1000  
tc 1
tc 3
tc convex-01 generator_random n=10 seed=1234 t=convex
tc convex-02 generator_random n=10 seed=1237 t=convex
tc convex-03 generator_random n=1000 seed=1230 t=convex
tc convex-04 generator_random n=1000 seed=1231 t=convex
tc outside-convex 


# (the one with seed=1004 is optimized at a non-cutoff point.
# this is harder to trigger with large n, so we don't bother.)
group 3-concave 38
limits mode="concave" maxN=1000 
tc 2
tc concave-01 generator_random n=10 t=concave
tc concave-02 generator_random n=10 t=concave
tc concave-03 generator_random n=10 t=concave
tc concave-04 generator_random n=10 seed=1004 t=concave
tc concave-05 generator_random n=1000 t=concave
tc concave-06 generator_random n=1000 t=concave
tc outside-concave

group 4-large 12
include_group sample
include_group 1-same-endpoint
include_group 2-convex
include_group 3-concave
tc large-01 generator_random n=100000 t=concave
tc large-02 generator_random n=100000 t=convex
tc large-03 generator_random n=100000 t=0.2
tc large-04 generator_random n=100000 t=0.8
tc large-05 generator_random n=10 t=0.2 seed=1032
tc large-06 generator_random n=10 t=0.2 seed=1055

