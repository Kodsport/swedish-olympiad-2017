#!/usr/bin/env bash

PPATH=$(realpath ..)

. ../../testdata_tools/gen.sh

use_solution bildaord_simon.cc

compile gen.py

samplegroup
sample 1
sample 2
sample 3
sample 4

group g1 60
limits maxN=9
include_group sample
tc_manual ../manual_testdata/manual01.in
tc_manual ../manual_testdata/manual02.in
tc g1-01 gen n=9 k=1
tc g1-02 gen n=9 k=5
tc g1-03 gen n=9 k=9
tc g1-04 gen n=9 k=9
tc_manual ../manual_testdata/skolkval1.in
tc_manual ../manual_testdata/skolkval2.in
tc_manual ../manual_testdata/skolkval3.in



group g2 40
include_group g1
#tc g2-01 gen n=15 k=1 even=15 # Det här blir för långsamt???
#tc g2-02 gen n=15 k=5 even=4
tc g2-03 gen n=15 k=10 even=3
tc g2-04 gen n=15 k=15 even=4
tc g2-05 gen n=15 k=15 even=4
tc_manual ../manual_testdata/skolkval4.in
tc_manual ../manual_testdata/skolkval5.in