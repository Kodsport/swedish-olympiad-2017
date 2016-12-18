#!/bin/bash

PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh

setup_dirs
use_solution arash_100.py
compile generator_all.py

# TODO 17-Dec Ändra för kubiska boxar
# TODO 17-Dec Ändra för kubiska boxar
# TODO 17-Dec Ändra för kubiska boxar
# TODO 17-Dec Ändra för kubiska boxar

group linje 30
tc g1-1 generator_all n=1000 l=10 mode=linje
tc g1-2 generator_all n=2000 l=20 mode=linje
tc g1-3 generator_all n=3000 l=30 mode=linje
tc g1-4 generator_all n=4000 l=40 mode=linje
tc g1-5 generator_all n=5000 l=50 mode=linje

group inge_nodkrig 30
tc g2-1 generator_all n=50  l=10 mode=inge_nodkrig
tc g2-2 generator_all n=60  l=20 mode=inge_nodkrig
tc g2-3 generator_all n=80  l=30 mode=inge_nodkrig
tc g2-4 generator_all n=100 l=04 mode=inge_nodkrig
tc g2-5 generator_all n=200 l=50 mode=inge_nodkrig

group normal 40
include_group linje
include_group inge_nodkrig
tc g3-1 generator_all n=100000 l=10 m=200000 mode=normal
tc g3-2 generator_all n=120000 l=20 m=240000 mode=normal
tc g3-3 generator_all n=140000 l=30 m=280000 mode=normal
tc g3-4 generator_all n=170000 l=04 m=300000 mode=normal
tc g3-5 generator_all n=200000 l=50 m=320000 mode=normal

generate_grader
cleanup_programs
