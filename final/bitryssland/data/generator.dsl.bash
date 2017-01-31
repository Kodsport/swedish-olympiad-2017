#!/bin/bash

PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh

setup_dirs
use_solution js_100.cpp

samplegroup
sample 1
sample 2

generate_grader
cleanup_programs
