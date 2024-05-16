#!/bin/bash
PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh

use_solution Skidor.java
compile copygen.py

samplegroup
sample 1

group 1_smallH 21
tc g1-1 copygen g1/H01
tc g1-2 copygen g1/H02
tc g1-3 copygen g1/H03

group 2_rc50 36
tc g2-1 copygen g2/50-1
tc g2-2 copygen g2/50-2
tc g2-3 copygen g2/50-3
tc g2-4 copygen g2/50-4
tc 1

group 3_rc300 27
include_group 2_rc50
tc g3-1 copygen g3/300
tc g3-2 copygen g3/300last
tc g3-3 copygen g3/300manytrees
tc g3-4 copygen g3/300rnd
tc g3-5 copygen g3/300tree

group 4_rc1000 16
include_group 1_smallH
include_group 2_rc50
include_group 3_rc300
tc g4-1 copygen g4/1000rnd
tc g4-2 copygen g4/1000rndnotree
