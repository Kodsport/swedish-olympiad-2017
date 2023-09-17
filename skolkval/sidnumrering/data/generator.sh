#!/usr/bin/env bash

PPATH=$(realpath ..)

. ../../testdata_tools/gen.sh

use_solution sidnumrering_johan.cpp

compile gen.py

samplegroup
sample 1
sample 2
sample 3

group g1 60
limits maxN=100000 
include_group sample
tc g1-01 gen n=1
tc g1-02 gen n=10
tc g1-03 gen n=100
tc g1-04 gen n=1000
tc g1-05 gen n=10000
tc g1-06 gen n=$((10**5))
tc g1-07 gen n=69420
tc g1-08 gen maxN=100000
tc g1-09 gen maxN=100000
tc g1-10 gen maxN=100000
tc_manual ../manual_testdata/sidnumrering01.in
tc_manual ../manual_testdata/sidnumrering02.in
tc_manual ../manual_testdata/sidnumrering03.in
tc_manual ../manual_testdata/manual1.in
tc_manual ../manual_testdata/manual2.in



group g2 40
include_group g1
tc g2-01 gen minN=$((10**9)) maxA=$((10**10))
tc g2-02 gen minN=$((10**9)) maxA=$((10**10))
tc g2-03 gen n=$((10**9))
tc g2-04 gen n=$((10**10))
tc g2-05 gen n=$((10**11))
tc g2-06 gen n=$((10**12))
tc g2-07 gen minN=$((10**6)) maxN=$((10**8))
tc g2-08 gen minN=$((10**9))
tc g2-09 gen minN=$((10**10))
tc g2-10 gen minN=$((10**10))
tc g2-11 gen n=100000000123
tc g2-12 gen n=100000000001
tc g2-13 gen n=123456789012
tc g2-14 gen n=999999999999
tc g2-15 gen n=999999999998
tc g2-16 gen n=100000001234
tc g2-17 gen minN=$((10**11))
tc g2-18 gen minN=$((10**5)) maxN=$((10**6))
tc g2-19 gen minN=$((10**6)) maxN=$((10**7))
tc g2-20 gen minN=$((10**7)) maxN=$((10**8))
tc g2-21 gen minN=$((10**8)) maxN=$((10**9))
tc g2-22 gen minN=$((10**9)) maxN=$((10**10))
tc_manual ../manual_testdata/sidnumrering04.in
tc_manual ../manual_testdata/sidnumrering05.in
