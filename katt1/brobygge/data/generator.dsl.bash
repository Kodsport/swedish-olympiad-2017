#!/bin/bash
PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh

setup_dirs
use_solution js_100.cpp
compile generator_line.py
compile generator_general.py

samplegroup
sample 1
sample 2
sample 3

group line 25
tc line-e0-01 generator_line n=100000 e=0
tc line-e0-02 generator_line n=100000 e=0
tc line-e0-03 generator_line n=100000 e=0
tc line-e0-04 generator_line n=100000 e=0
tc line-e1-01 generator_line n=100000 e=1
tc line-e1-02 generator_line n=100000 e=1
tc line-e1-03 generator_line n=100000 e=1
tc line-e1-04 generator_line n=100000 e=1
tc line-e2-01 generator_line n=100000 e=2
tc line-e2-02 generator_line n=100000 e=2
tc line-e2-03 generator_line n=100000 e=2
tc line-e2-04 generator_line n=100000 e=2

subgroup() {
	group e$1 25
	tc line-e$1-01
	tc line-e$1-02
	tc line-e$1-03
	tc line-e$1-04
	tc general-e$1-01 generator_general n=100000 e=$1
	tc general-e$1-02 generator_general n=100000 e=$1
	tc general-e$1-03 generator_general n=100000 e=$1
	tc general-e$1-04 generator_general n=100000 e=$1
	tc star-e$1-01 generator_general n=100000 e=$1 c=5
	tc star-e$1-02 generator_general n=100000 e=$1 c=5
	tc star-e$1-03 generator_general n=100000 e=$1 c=5
	tc star-e$1-04 generator_general n=100000 e=$1 c=5
}

subgroup 0
subgroup 1
subgroup 2

generate_grader
generate_cms
cleanup_programs
