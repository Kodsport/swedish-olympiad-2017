#!/bin/bash
PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh


use_solution emanuel.cpp
compile generator_periodic.py
compile generator_zero.py
compile generator_rnd.py

samplegroup
limits maxn=100 maxk=10
sample 1
sample 2

group 1-small 8
limits k_2=1 maxk=2 maxn=100
tc 2
tc small-01 generator_zero n=100 k=2
tc small-02 generator_rnd n=100 k=2
tc small-03 generator_rnd n=100 k=2
tc small-04 generator_periodic n=100 k=2
tc small-05 generator_periodic n=100 k=2

group 2-bruteforce 10
limits maxk=7 maxn=100
include_group 1-small
tc 1
tc bruteforce-01 generator_zero n=100 k=7
tc bruteforce-02 generator_rnd n=100 k=7
tc bruteforce-03 generator_rnd n=100 k=7
tc bruteforce-04 generator_periodic n=100 k=7
tc bruteforce-05 generator_periodic n=100 k=7

group 3-dp 28
limits maxk=10 maxn=1000
include_group 2-bruteforce
tc dp-01 generator_zero n=1000 k=10
tc dp-02 generator_zero n=1000 k=10
tc dp-03 generator_rnd n=1000 k=10
tc dp-04 generator_rnd n=1000 k=10
tc dp-05 generator_rnd n=1000 k=10
tc dp-06 generator_periodic n=1000 k=10
tc dp-07 generator_periodic n=1000 k=10
tc dp-08 generator_periodic n=1000 k=10

group 4-precompute-bf 19
limits maxk=10 maxn=1000000
include_group 3-dp
tc precompute-bf-01 generator_zero n=1000000 k=10
tc precompute-bf-02 generator_zero n=1000000 k=10
tc precompute-bf-03 generator_rnd n=1000000 k=10
tc precompute-bf-04 generator_rnd n=1000000 k=10
tc precompute-bf-05 generator_rnd n=1000000 k=10
tc precompute-bf-06 generator_periodic n=1000000 k=10
tc precompute-bf-07 generator_periodic n=1000000 k=10
tc precompute-bf-08 generator_periodic n=1000000 k=10

group 5-precompute-dp 35
limits maxk=18 maxn=1000000
include_group 4-precompute-bf
tc precompute-dp-01 generator_zero n=1000000 k=18
tc precompute-dp-02 generator_zero n=1000000 k=18
tc precompute-dp-03 generator_zero n=1000000 k=18
tc precompute-dp-04 generator_rnd n=1000000 k=18
tc precompute-dp-05 generator_rnd n=1000000 k=18
tc precompute-dp-06 generator_rnd n=1000000 k=18
tc precompute-dp-07 generator_periodic n=1000000 k=18
tc precompute-dp-08 generator_periodic n=1000000 k=18
tc precompute-dp-09 generator_periodic n=1000000 k=18

