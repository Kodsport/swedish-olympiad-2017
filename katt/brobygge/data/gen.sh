#!/bin/bash
REQUIRE_SAMPLE_REUSE=0
PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh

# Use the specified solution file for validation
use_solution js_100.cpp

# Compile the generator Python scripts
compile generator_line.py
compile generator_general.py

# Define a sample group and include specific sample cases
samplegroup
sample 1
sample 2
sample 3

# Define a test group for 'line' configurations
group 1-line 25
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

group 2-e0 25
limits e=0
tc 1
tc line-e0-01
tc line-e0-02
tc line-e0-03
tc line-e0-04
tc general-e0-01 generator_general n=100000 e=0
tc general-e0-02 generator_general n=100000 e=0
tc general-e0-03 generator_general n=100000 e=0
tc general-e0-04 generator_general n=100000 e=0
tc star-e0-01 generator_general n=100000 e=0 c=5
tc star-e0-02 generator_general n=100000 e=0 c=5
tc star-e0-03 generator_general n=100000 e=0 c=5
tc star-e0-04 generator_general n=100000 e=0 c=5

group 3-e1 25
limits e=1
tc 2
tc line-e1-01
tc line-e1-02
tc line-e1-03
tc line-e1-04
tc general-e1-01 generator_general n=100000 e=1
tc general-e1-02 generator_general n=100000 e=1
tc general-e1-03 generator_general n=100000 e=1
tc general-e1-04 generator_general n=100000 e=1
tc star-e1-01 generator_general n=100000 e=1 c=5
tc star-e1-02 generator_general n=100000 e=1 c=5
tc star-e1-03 generator_general n=100000 e=1 c=5
tc star-e1-04 generator_general n=100000 e=1 c=5

group 4-e2 25
limits e=2
tc 3
tc line-e2-01
tc line-e2-02
tc line-e2-03
tc line-e2-04
tc general-e2-01 generator_general n=100000 e=2
tc general-e2-02 generator_general n=100000 e=2
tc general-e2-03 generator_general n=100000 e=2
tc general-e2-04 generator_general n=100000 e=2
tc star-e2-01 generator_general n=100000 e=2 c=5
tc star-e2-02 generator_general n=100000 e=2 c=5
tc star-e2-03 generator_general n=100000 e=2 c=5
tc star-e2-04 generator_general n=100000 e=2 c=5
