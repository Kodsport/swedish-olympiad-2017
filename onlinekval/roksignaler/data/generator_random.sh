#!/bin/bash
cat morse_table
python3 genrandom.py $@ | python3 genmsg.py
