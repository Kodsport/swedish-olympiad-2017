#!/bin/bash
PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh


use_solution nils_100.cpp
compile gen_random.py
compile gen_line.py
compile gen_greedykiller.py
compile gen_flower.py
compile gen_abacaba.py
compile gen_hardline.py

samplegroup
sample 1
sample 2

group 1-small 25
include_group sample
tc small-01 gen_random n=89 m=3916
tc small-02 gen_random n=1000 m=4000
tc small-03 gen_random n=1000 m=4000
tc small-04 gen_random n=1000 m=0
tc small-05 gen_random n=1000 m=2000 maxh=0
tc small-06 gen_random n=1 m=0
tc small-07 gen_flower n=1000
tc small-08 gen_line n=1000

group 2-line 25
tc line-01 gen_line n=100000
tc line-02 gen_line n=100000
tc line-03 gen_line n=100000
tc line-04 gen_line n=100000 maxh=0
tc line-05 gen_line n=100000 maxh=1
tc line-06 gen_line n=1
tc line-07 gen_abacaba n=100000
tc line-08 gen_hardline n=100000

group 3-large 50
include_group 1-small
include_group 2-line
tc large-01 gen_random n=100000 m=400000
tc large-02 gen_random n=100000 m=400000
tc large-03 gen_random n=100000 m=50000
tc large-04 gen_random n=890 m=395605
tc large-05 gen_flower n=100000
tc large-06 gen_greedykiller n=99999

