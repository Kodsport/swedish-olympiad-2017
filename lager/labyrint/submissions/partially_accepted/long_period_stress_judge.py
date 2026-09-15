# On case 1, this will make the output validator pretty slow
import random
random.seed(4)
n=196000

def generate_evil(n):
    out = [[] for i in range(n)]
    for c in range(3):
        p = list(range(n))
        random.shuffle(p)
        matching = list(range(n//2, n))
        random.shuffle(matching)

        ub=n//2
        if c == 2:
            ub -= 1
        for i in range(ub):
            e = (p[i],p[matching[i]])
            out[e[0]].append(e[1])
            out[e[1]].append(e[0])

    missing_blue = [i for i in range(n) if len(out[i])==2]
    a,b=missing_blue

    n = len(out)
    safety_chain_len = 2000
    base_1 = n
    base_2 = n+safety_chain_len
    while len(out) < n+safety_chain_len*2:
        out.append([-1]*3)
    for i in range(len(out)):
        while len(out[i])<3:
            out[i].append(-1)
    def add_e(a,b,ind):
        out[a][ind] = b
        out[b][ind] = a
    add_e(a, base_1, 2)
    add_e(b, base_2, 2)
    p = 0
    for i in range(base_1, n+safety_chain_len-1):
        if p % 2 ==0:
            add_e(i,i+1,0)
            add_e(i,i+1,1)
        else:
            add_e(i,i+1,2)
        p+=1
    p=0
    for i in range(base_2, n+safety_chain_len*2-1):
        if p % 2 ==0:
            add_e(i,i+1,0)
            add_e(i,i+1,1)
        else:
            add_e(i,i+1,2)
        p+=1

    add_e(base_2-1, base_2 + safety_chain_len-1, 2)

    return out

adj = generate_evil(n)
print(len(adj), 0, len(adj)-1)
for o in adj:
    print(*o)
