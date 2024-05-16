#!/usr/bin/env bash

PPATH=$(realpath ..)
REQUIRE_SAMPLE_REUSE=0
. ../../testdata_tools/gen.sh

use_solution simon.cpp

compile gen_det.py

group g01 10
tc case01 gen_det N=100_000 W=1000 T=1

group g02 10
tc case02 gen_det N=75 W=11 lo=3 hi=5 T=2

group g03 10
tc case03 gen_det N=5000 W=100 T=3

group g04 10
tc case04 gen_det N=1000 W=1000 T=4

group g05 10
tc case05 gen_det N=100_000 W=1000 T=5

group g06 10
tc case06 gen_det N=100_000 W=100_000 T=6

group g07 10
tc case07 gen_det N=100_000 W=50 lo=5 hi=10 T=7

group g08 10
tc case08 gen_det N=100 W=50000 lo=400 hi=600 T=8

group g09 10
tc case09 gen_det N=60 W=15 lo=1 hi=5 T=9

group g10 10
tc case10 gen_det N=100_000 W=1000 T=10

echo 'grading: custom' >> testdata.yaml
echo 'grading: default' >> secret/testdata.yaml
echo 'grading: default' >> sample/testdata.yaml