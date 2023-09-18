#!/usr/bin/env bash

PPATH=$(realpath ..)

. ../../testdata_tools/gen.sh

use_solution armstod_par.cpp

compile gen.py

samplegroup
sample armstod1
sample armstod2
sample armstod3

group g1 20
limits maxN=5 firstI=1
tc armstod2
tc g1-01 gen n=5 firstI=1
tc g1-02 gen n=5 firstI=1 V=0 H=0 A=0 B=0 I=1
tc g1-03 gen n=5 firstI=1 V=0 H=0 A=0 B=1 I=0
tc g1-04 gen n=5 firstI=1 V=0 H=0 A=1 B=0 I=0
tc g1-05 gen n=5 firstI=1 V=0 H=1 A=0 B=0 I=0
tc g1-06 gen n=5 firstI=1 V=1 H=0 A=0 B=0 I=0
tc g1-07 gen n=5 firstI=1 V=1 H=1 A=0 B=0 I=0
tc g1-08 gen n=5 firstI=1 V=0 H=0 A=1 B=1 I=0
tc g1-09 gen n=5 firstI=1 V=0 H=2 A=1 B=0 I=0
tc g1-10 gen n=5 firstI=1 V=0 H=0 A=0 B=3 I=1
tc g1-11 gen n=5 firstI=1 V=0 H=0 A=0 B=2 I=1
tc g1-12 gen n=5 firstI=1
tc g1-13 gen n=5 firstI=1
tc g1-14 gen n=5 firstI=1
tc g1-15 gen n=5 firstI=1 repeat=2
tc g1-16 gen n=5 firstI=1 repeat=2 V=1 A=1 H=0 I=0 B=0
tc g1-17 gen n=5 firstI=1 repeat=2 V=0 A=1 H=1 I=0 B=0
tc g1-18 gen n=5 firstI=1 repeat=2
tc g1-19 gen n=5 firstI=1 repeat=2 I=0
tc g1-20 gen n=5 firstI=1 repeat=4 I=0 seed=1
tc_manual ../manual_testdata/armstod.g1.1.in
tc_manual ../manual_testdata/armstod.g1.2.in
tc_manual ../manual_testdata/manual4.in
tc_manual ../manual_testdata/manual5.in

group g2 40
limits maxN=15
include_group g1
include_group sample
tc g2-01 gen n=6
tc g2-02 gen n=8
tc g2-03 gen n=10
tc g2-04 gen n=11
tc g2-05 gen n=14
tc g2-06 gen n=15
tc g2-07 gen maxN=15 V=0 H=0 A=0 B=0 I=1
tc g2-08 gen maxN=15 V=0 H=0 A=0 B=1 I=0
tc g2-09 gen maxN=15 V=0 H=0 A=1 B=0 I=0
tc g2-10 gen maxN=15 V=0 H=1 A=0 B=0 I=0
tc g2-11 gen maxN=15 V=1 H=0 A=0 B=0 I=0
tc g2-12 gen maxN=15 V=1 H=3 A=0 B=0 I=0
tc g2-13 gen n=15 V=1 H=7 A=0 B=0 I=0
tc g2-14 gen maxN=15 V=3 H=1 A=0 B=0 I=0
tc g2-15 gen n=15 V=7 H=1 A=0 B=0 I=0
tc g2-16 gen n=15 V=0 H=0 A=0 B=7 I=3
tc g2-17 gen maxN=15 V=0 H=0 A=1 B=3 I=0
tc g2-18 gen n=15 V=0 H=0 A=1 B=9 I=0
tc g2-19 gen n=15 V=0 H=0 A=9 B=1 I=0
tc g2-20 gen maxN=15 V=0 H=0 A=3 B=1 I=0
tc g2-21 gen maxN=15 repeat=2
tc g2-22 gen maxN=15 repeat=2
tc g2-23 gen maxN=15 repeat=2
tc g2-24 gen n=15 repeat=2
tc g2-25 gen maxN=15 repeat=2
tc g2-26 gen n=9 repeat=3
tc g2-27 gen n=10 repeat=3
tc g2-28 gen n=15 repeat=3
tc g2-29 gen n=14 repeat=4
tc g2-30 gen n=15 repeat=4
tc g2-31 gen n=15 repeat=5
tc g2-32 gen n=15 repeat=3 B=1 I=2 H=0 V=0 A=0
tc g2-33 gen n=15 repeat=3 B=2 I=1 H=0 V=0 A=0
tc g2-34 gen n=15 repeat=3 B=2 V=1 H=0 I=0 A=0
tc g2-35 gen n=15 repeat=3 B=2 H=1 V=0 I=0 A=0
tc g2-36 gen n=15 repeat=3 V=2 H=1 B=0 I=0 A=0
tc g2-37 gen n=15 repeat=3 V=1 H=2 B=0 I=0 A=0
tc g2-38 gen n=15 repeat=3 A=2 H=1 B=0 I=0 V=0
tc g2-39 gen n=15 repeat=3 B=2 A=1 H=0 I=0 V=0
tc g2-40 gen n=15 repeat=3 H=2 B=1 A=0 I=0 V=0
tc_manual ../manual_testdata/armstod.g2.1.in
tc_manual ../manual_testdata/armstod.g2.2.in
tc_manual ../manual_testdata/armstod.g3.1.in
tc_manual ../manual_testdata/armstod.g3.2.in
tc_manual ../manual_testdata/manual1.in
tc_manual ../manual_testdata/manual2.in

group g3 20
limits firstI=1
include_group g1
tc g3-01 gen n=30 firstI=1
tc g3-02 gen firstI=1 V=0 H=0 A=0 B=0 I=1
tc g3-03 gen firstI=1 V=0 H=0 A=0 B=1 I=0
tc g3-04 gen firstI=1 V=0 H=0 A=1 B=0 I=0
tc g3-05 gen firstI=1 V=0 H=1 A=0 B=0 I=0
tc g3-06 gen firstI=1 V=1 H=0 A=0 B=0 I=0
tc g3-07 gen firstI=1 V=1 H=1 A=0 B=0 I=0
tc g3-08 gen firstI=1 V=0 H=0 A=1 B=1 I=0
tc g3-09 gen firstI=1 V=0 H=0 A=0 B=1 I=1
tc g3-10 gen firstI=1 V=0 H=0 A=0 B=3 I=1
tc g3-11 gen firstI=1 V=0 H=0 A=0 B=3 I=1
tc g3-12 gen n=25 firstI=1
tc g3-13 gen firstI=1
tc g3-14 gen firstI=1
tc g3-15 gen firstI=1 repeat=2
tc g3-16 gen firstI=1 repeat=2
tc g3-17 gen firstI=1 repeat=2
tc g3-18 gen n=30 firstI=1 repeat=2
tc g3-19 gen n=29 firstI=1 repeat=2
tc g3-20 gen n=28 firstI=1 repeat=2
tc g3-21 gen n=30 firstI=1 repeat=3
tc g3-22 gen n=29 firstI=1 repeat=3
tc g3-23 gen n=28 firstI=1 repeat=3
tc g3-24 gen n=30 firstI=1 repeat=3
tc g3-25 gen n=29 firstI=1 repeat=3
tc g3-26 gen n=28 firstI=1 repeat=3
tc g3-27 gen n=30 firstI=1 repeat=4
tc g3-28 gen n=29 firstI=1 repeat=4
tc g3-29 gen n=28 firstI=1 repeat=4
tc g3-30 gen n=27 firstI=1 repeat=4
tc g3-31 gen n=30 firstI=1 repeat=5
tc g3-32 gen n=29 firstI=1 repeat=5
tc g3-33 gen n=28 firstI=1 repeat=5
tc g3-34 gen n=30 firstI=1 repeat=3 B=1 I=2 H=0 V=0 A=0
tc g3-35 gen n=30 firstI=1 repeat=3 B=2 I=1 H=0 V=0 A=0
tc g3-36 gen n=30 firstI=1 repeat=3 B=2 V=1 H=0 I=0 A=0
tc g3-37 gen n=30 firstI=1 repeat=3 B=2 H=1 V=0 I=0 A=0
tc g3-38 gen n=30 firstI=1 repeat=3 V=2 H=1 B=0 I=0 A=0
tc g3-39 gen n=30 firstI=1 repeat=3 V=1 H=2 B=0 I=0 A=0
tc g3-40 gen n=30 firstI=1 repeat=3 A=2 H=1 B=0 I=0 V=0
tc g3-41 gen n=30 firstI=1 repeat=3 B=2 A=1 H=0 I=0 V=0
tc g3-42 gen n=30 firstI=1 repeat=3 H=2 B=1 A=0 I=0 V=0
tc g3-43 gen n=30 firstI=1 V=0 H=0 A=1 B=6 I=0
tc g3-44 gen n=30 firstI=1 V=3 H=3 A=1 B=0 I=0
tc g3-45 gen n=30 firstI=1 V=3 H=3 A=2 B=0 I=0
tc_manual ../manual_testdata/armstod.g4.1.in
tc_manual ../manual_testdata/manual6.in
tc_manual ../manual_testdata/manual7.in

group g4 20
include_group g2
include_group g3
tc g4-01 gen n=30
tc g4-02 gen V=0 H=0 A=0 B=0 I=1
tc g4-03 gen V=0 H=0 A=0 B=1 I=0
tc g4-04 gen V=0 H=0 A=1 B=0 I=0
tc g4-05 gen V=0 H=1 A=0 B=0 I=0
tc g4-06 gen V=1 H=0 A=0 B=0 I=0
tc g4-07 gen V=1 H=1 A=0 B=0 I=0
tc g4-08 gen V=0 H=0 A=1 B=1 I=0
tc g4-09 gen V=0 H=0 A=0 B=1 I=1
tc g4-10 gen V=0 H=0 A=0 B=3 I=1
tc g4-11 gen V=0 H=0 A=0 B=3 I=1
tc g4-12 gen n=25
tc g4-13 gen
tc g4-14 gen
tc g4-15 gen repeat=2
tc g4-16 gen repeat=2
tc g4-17 gen repeat=2
tc g4-18 gen n=30 repeat=2
tc g4-19 gen n=29 repeat=2
tc g4-20 gen n=28 repeat=2
tc g4-21 gen n=30 repeat=3
tc g4-22 gen n=29 repeat=3
tc g4-23 gen n=28 repeat=3
tc g4-24 gen n=30 repeat=3
tc g4-25 gen n=29 repeat=3
tc g4-26 gen n=28 repeat=3
tc g4-27 gen n=30 repeat=4
tc g4-28 gen n=29 repeat=4
tc g4-29 gen n=28 repeat=4
tc g4-30 gen n=27 repeat=4
tc g4-31 gen n=30 repeat=5
tc g4-32 gen n=29 repeat=5
tc g4-33 gen n=28 repeat=5
tc g4-34 gen n=30 repeat=4 B=1 I=3 H=0 V=0 A=0
tc g4-35 gen n=30 repeat=6 B=5 I=1 H=0 V=0 A=0
tc g4-36 gen n=30 repeat=3 B=2 V=1 H=0 I=0 A=0
tc g4-37 gen n=30 repeat=3 B=2 H=1 V=0 I=0 A=0
tc g4-38 gen n=30 repeat=3 V=2 H=1 B=0 I=0 A=0
tc g4-39 gen n=30 repeat=3 V=1 H=2 B=0 I=0 A=0
tc g4-40 gen n=30 repeat=3 A=2 H=1 B=0 I=0 V=0
tc g4-41 gen n=30 repeat=3 B=2 A=1 H=0 I=0 V=0
tc g4-42 gen n=30 repeat=3 H=2 B=1 A=0 I=0 V=0
tc g4-43 gen n=30 V=0 H=0 A=1 B=6 I=0
tc g4-44 gen n=30 V=3 H=3 A=1 B=0 I=0
tc g4-45 gen n=30 V=3 H=3 A=2 B=0 I=0
tc_manual ../manual_testdata/armstod.g5.1.in
tc_manual ../manual_testdata/manual3.in
