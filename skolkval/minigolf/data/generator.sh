#!/usr/bin/env bash

PPATH=$(realpath ..)

. ../../testdata_tools/gen.sh

use_solution minigolf.cpp

compile gen.py

samplegroup
sample 1
sample 2

group g1 40
limits maxA=7 minA=1
tc g1-01 gen n=2 maxA=1
tc g1-02 gen n=10 maxA=1
tc g1-03 gen n=2 maxA=2
tc g1-04 gen minA=2 maxA=2 
tc g1-05 gen minA=2 maxA=5 
tc g1-06 gen minA=5 maxA=7 
tc g1-07 gen n=9 minA=7 maxA=7 
tc g1-08 gen maxA=7
tc g1-09 gen maxA=7 n=10
tc g1-10 gen maxA=7 n=10
tc_manual ../manual_testdata/manual03.in
tc_manual ../manual_testdata/manual04.in
tc_manual ../manual_testdata/skolkval5.in
tc_manual ../manual_testdata/skolkval2.in
tc_manual ../manual_testdata/skolkval1.in




group g2 60
limits maxA=10 minA=1
include_group g1
include_group sample
tc g2-01 gen n=2 minA=6
tc g2-02 gen n=7 minA=8
tc g2-03 gen n=4 minA=8 maxA=8 
tc g2-04 gen n=9 minA=10
tc g2-05 gen n=5 
tc g2-06 gen n=6 maxA=9
tc g2-07 gen n=8
tc g2-08 gen n=10
tc g2-09 gen n=10 minA=4
tc g2-10 gen n=10
tc g2-11 gen n=10
tc g2-12 gen n=10
tc g2-13 gen n=10
tc_manual ../manual_testdata/manual01.in
tc_manual ../manual_testdata/manual02.in
tc_manual ../manual_testdata/manual05.in
tc_manual ../manual_testdata/skolkval4.in
tc_manual ../manual_testdata/skolkval3.in
