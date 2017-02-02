#!/bin/bash

PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh

setup_dirs
use_solution validator.cpp
compile gen.cpp

samplegroup
for x in {1..2}
do
    sample $x
done

group small-nodouble 0
tc filled-01 gen 10 filled 
tc filled-02 gen 10 filled 
tc splithole-06 gen 1000 splithole

group small 34
include_group small-nodouble
tc okholes-10 gen 100000 okholes 

tc splithole-07 gen 10000 splithole
tc splithole-09 gen 100000 splithole
tc splithole-10 gen 100000 splithole 

group large 35
include_group small
include_group large-nodouble
tc doublehole-09 gen 100000 doublehole
tc doublehole-10 gen 100000 doublehole 

tc pyramid2-02 gen 100000 pyramid2

generate_grader
cleanup_programs
