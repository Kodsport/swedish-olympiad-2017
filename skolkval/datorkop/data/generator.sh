#!/usr/bin/env bash

PPATH=$(realpath ..)

. ../../../testdata_tools/gen.sh

use_solution datorkop_fast.cpp

compile gen.py
compile gen_hard.py
compile gen_greedy.py

samplegroup
sample 1
sample 2
sample 3


group g1 20
limits maxN=2 maxXY=100
tc 1
tc g1-01 gen n=2 maxXY=100
tc g1-02 gen n=2 maxXY=100
tc g1-03 gen n=2 maxXY=100
tc_manual ../manual_testdata/manual-11.in
tc_manual ../manual_testdata/manual-13.in
tc_manual ../manual_testdata/manual-12.in
tc_manual ../manual_testdata/datorkop01.in

group g2 20
limits maxN=6 maxXY=10
tc 2
tc g2-01 gen n=3 maxXY=10
tc g2-02 gen n=4 maxXY=10
tc g2-03 gen n=5 maxXY=10
tc g2-04 gen n=6 maxXY=10
tc g2-05 gen_greedy mode=tight13 x=9 a=684 b=988
tc_manual ../manual_testdata/datorkop02.in

group g3 40
limits maxN=100 maxXY=100
include_group g1 g2
tc 3
tc g3-01 gen n=10 maxXY=100
tc g3-02 gen n=50 maxXY=100
tc g3-03 gen n=100 maxXY=10
tc g3-04 gen n=100 maxXY=100
tc g3-05 gen_greedy mode=tight13 x=100 a=684 b=988
tc_manual ../manual_testdata/datorkop03.in
tc_manual ../manual_testdata/datorkop04.in

group g4 20
include_group g3
tc g4-01 gen n=800 maxXY=1000
tc g4-02 gen n=900 maxXY=1000
tc g4-03 gen n=1000 maxXY=1000
tc g4-04 gen n=1000 maxXY=1000
tc g4-05 gen_hard n=800 maxXY=1000
tc g4-06 gen_greedy mode=tight31 n=900 y=890 a=330 b=700
tc_manual ../manual_testdata/manual-41.in
tc_manual ../manual_testdata/manual-42.in
tc_manual ../manual_testdata/manual-43.in
tc_manual ../manual_testdata/manual-44.in
tc_manual ../manual_testdata/manual-45.in
tc_manual ../manual_testdata/manual-46.in
tc_manual ../manual_testdata/datorkop05.in

