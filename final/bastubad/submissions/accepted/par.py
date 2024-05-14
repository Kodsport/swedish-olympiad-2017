import sys

def p(a,b,c,x) : return a*x*x+b*x+c

def tabc(line):
    a,b,c,t = line.split()
    return (int(t),float(a),float(b),float(c)) 

people=[tabc(line) for line in sys.stdin.readlines()[1:]]
people.sort(reverse=True)
best=0.0
aa=bb=cc=0.0
for t,a,b,c in people:
    aa+=a
    bb+=b
    cc+=c
    y1=p(aa,bb,cc,0.0)
    y2=p(aa,bb,cc,t)
    best=max(best,y1,y2)
    if aa!=0.0:
        x3=-0.5*bb/aa
        if x3>0.0 and x3<t:
            y3=p(aa,bb,cc, -0.5*bb/aa)
            best=max(best,y3)
print(best)
