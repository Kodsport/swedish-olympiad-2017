# Just a quick file I write to compare answers between two files

arash () { python3 submissions/accepted/arash_100.py }
g++ submissions/accepted/simon.cpp -g -O2 -static -std=gnu++11 -o submissions/accepted/simon
simon () { ./submissions/accepted/simon }

comp () { cat > /tmp/lol; diff <(arash < /tmp/lol) <(simon < /tmp/lol) }
gen () { python3 data/generator_all.py $@ }

# Eventually I used the file like this:
# each 'echo $x; gen n=4 l=3 m=5 mode=normal $x | comp' {1..100}
