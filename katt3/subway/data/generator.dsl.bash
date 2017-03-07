#!/bin/bash
PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh

setup_dirs
use_solution simon.cpp
compile gen_general.py

samplegroup
sample 1
sample 2

addgroup(){
	tc $1-01 gen_general n=$2 a=tree b=tree
	tc $1-02 gen_general n=$2 a=tree b=tree
	tc $1-03 gen_general n=$2 a=tree b=tree
	tc $1-04 gen_general n=$2 a=tree b=tree
	tc $1-05 gen_general n=$2 a=tree b=tree
	tc $1-06 gen_general n=$2 a=tree b=tree

	tc $1-07 gen_general n=$2 a=tree b=line
	tc $1-08 gen_general n=$2 a=line b=tree
	tc $1-09 gen_general n=$2 a=line b=line

	tc $1-10 gen_general n=$2 a=star b=tree
	tc $1-11 gen_general n=$2 a=star b=line
	tc $1-12 gen_general n=$2 a=tree b=star
	tc $1-13 gen_general n=$2 a=line b=star
	tc $1-14 gen_general n=$2 a=star b=star
}

group small 33
addgroup small 10

group mid 33
include_group small
addgroup medium 1000

group large 34
include_group mid
addgroup large 100000

generate_grader
cleanup_programs
