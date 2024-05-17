#!/bin/bash
REQUIRE_SAMPLE_REUSE=0
PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh

use_solution arash_100.py
compile generator_all.py

samplegroup
sample 1
sample 2
sample 3
sample 4

group 1-enforce_rgb 50
tc g1-1 generator_all n=100  max_l=100000 enforce_rgb=yes
tc g1-2 generator_all n=200  max_l=200000 enforce_rgb=yes
tc g1-3 generator_all n=300  max_l=300000 enforce_rgb=yes
tc g1-4 generator_all n=400  max_l=400000 enforce_rgb=yes
tc g1-5 generator_all n=1000 max_l=500000 enforce_rgb=yes

group 2-all 50
include_group 1-enforce_rgb
tc g2-1 generator_all n=100  max_l=100000
tc g2-2 generator_all n=200  max_l=200000
tc g2-3 generator_all n=300  max_l=300000
tc g2-4 generator_all n=400  max_l=400000
tc g2-5 generator_all n=1000 max_l=500000