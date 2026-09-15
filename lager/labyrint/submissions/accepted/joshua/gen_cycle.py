s=input()
# Only needed for case 1, where s[i]!=s[i+1]

num_nodes = len(s)+2
adj = [[-1]*3 for i in range(num_nodes)]

def remap(c):
    if c=='R':
        return 0
    if c=='G':
        return 1
    if c=='B':
        return 2

for i in range(len(s)):
    col = remap(s[i])
    adj[i][col] = (i+1)%len(s)
    adj[(i+1)%len(s)][col] = i

for col in range(3):
    inds = [i for i in range(len(s)) if adj[i][col] == -1]
    assert len(inds) % 2 == 0
    if col == 0:
        u1,u2 = inds[-1],inds[-2]
        del inds[-1]
        del inds[-1]
        g1 = num_nodes-1
        g2 = num_nodes-2
        adj[u1][0] = g1
        adj[g1][0] = u1
        adj[u2][0] = g2
        adj[g2][0] = u2

        adj[g1][1] = g2
        adj[g1][2] = g2
        adj[g2][1] = g1
        adj[g2][2] = g1

    while len(inds):
        u1,u2 = inds[-1],inds[-2]
        del inds[-1]
        del inds[-1]
        adj[u1][col] = u2
        adj[u2][col] = u1

print(num_nodes, 0, num_nodes-1)
for i in range(num_nodes):
    print(*adj[i])
