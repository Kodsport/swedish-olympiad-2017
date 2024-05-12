#!/usr/bin/env bash

PPATH=$(realpath ..)

. ../../testdata_tools/gen.sh

use_solution datorkop_par.cpp

compile gen.py

samplegroup
sample 1
sample 2
sample 3


group g1 20
limits minN=2 maxN=2 maxXY=100
tc 1
tc g1-01 gen n=2 maxXY=100
tc g1-02 gen n=2 maxXY=100
tc g1-03 gen n=2 maxXY=100
tc_manual ../manual_testdata/datorkop01.in

group g2 20
limits minN=3 maxN=6 maxXY=10
tc 2
tc g2-01 gen n=3 maxXY=10
tc g2-02 gen n=4 maxXY=10
tc g2-03 gen n=5 maxXY=10
tc g2-04 gen n=6 maxXY=10
tc_manual ../manual_testdata/datorkop02.in

group g3 40
limits minN=10 maxN=100 maxXY=100
tc 3
tc g3-01 gen n=10 maxXY=100
tc g3-02 gen n=50 maxXY=100
tc g3-03 gen n=100 maxXY=10
tc g3-04 gen n=100 maxXY=100
tc_manual ../manual_testdata/datorkop03.in
tc_manual ../manual_testdata/datorkop04.in

group g4 20
limits minN=800 maxN=1000
tc g4-01 gen n=800 maxXY=1000
tc g4-02 gen n=900 maxXY=1000
tc g4-03 gen n=1000 maxXY=1000
tc_manual ../manual_testdata/manual-41.in
tc_manual ../manual_testdata/manual-42.in
tc_manual ../manual_testdata/manual-43.in
tc_manual ../manual_testdata/manual-44.in
#tc_manual ../manual_testdata/datorkop05.in   # did not follow the constraints.

