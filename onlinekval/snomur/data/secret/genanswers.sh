#!/bin/bash

CASES=(01 02 03 04 05 06 07 08 09 10) 

for x in ${CASES[*]}
do
	python3 genans.py < snomur$x.in > snomur$x.ans
done
