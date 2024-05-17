#!/bin/bash
REQUIRE_SAMPLE_REUSE=0
PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh

use_solution david.cpp
compile generator_existing.py
compile generator_random.py

samplegroup
sample sample1

group g1
tc_manual ../manual_data/1.in
tc_manual ../manual_data/2.in
tc_manual ../manual_data/3.in
tc_manual ../manual_data/4.in
tc_manual ../manual_data/5.in
tc_manual ../manual_data/6.in
tc_manual ../manual_data/7.in
tc_manual ../manual_data/8.in
tc_manual ../manual_data/9.in
tc_manual ../manual_data/10.in
#tc tiny-ex generator_existing n=6 m=6
#tc small generator_existing n=10 m=7 dup=0
#tc small-pad generator_existing n=10 m=7 padding=100
#tc small-rand generator_random m=15
#tc small-ex generator_existing n=10 m=4000 dup=0
#tc medium-rand generator_random m=100
#tc medium-ex generator_existing n=100 m=400 dup=0
#tc large-ex generator_existing n=200 m=2000
#tc huge generator_random m=100000 dup=0
#tc huge-pad generator_random m=1 padding=200000
