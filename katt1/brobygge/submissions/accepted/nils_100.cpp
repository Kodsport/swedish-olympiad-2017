#include <bits/stdc++.h>

using namespace std;

int const inf = 1000000007;

struct Tree{
    vector<vector<int> > C;
    vector<vector<int> > CW;
    vector<int> line;
    vector<int> labels;
    vector<int> invlabels;
    vector<int> depth;
    vector<int> FL;
    vector<vector<int> > ST;
    int d = 0;

    void dfs(int i, int par){
        if(labels[i] == -1){
            labels[i] = d;
            invlabels.push_back(i);
            FL[i] = line.size();
            d++;
        }
        int l = labels[i];
        line.push_back(l);
        for(int c1 = 0; c1 < C[i].size(); c1++){
            int j = C[i][c1];
            if(j != par){
                depth[j] = depth[i] + CW[i][c1];
                dfs(j,i);
                line.push_back(l);
            }
        }
    }

    int lca(int i, int j){
        int a = min(FL[i],FL[j]);
        int b = max(FL[i],FL[j]);
        int dep = 31 - __builtin_clz(b+1-a);
        int l = min(ST[dep][a] , ST[dep][b + 1 - (1 << dep)]);
        return invlabels[l];
    }

    int dist(int i, int j){
        return depth[i]+depth[j]-2*depth[lca(i,j)];
    }

    void setup(){
        for(int c1 = 0; c1 < C.size(); c1++){
            labels.push_back(-1);
            depth.push_back(0);
            FL.push_back(0);
        }
        dfs(0,-1);
        int t = 1;
        int p = 1;
        while(t < line.size()){
            t *= 2;
            p++;
        }
        for(int c1 = 0; c1 < p; c1++){
            vector<int> V;
            ST.push_back(V);
        }
        int N = line.size();
        for(int c1 = 0; c1 < p; c1++){
            for(int c2 = 0; c2 < N; c2++){
                if(c1 == 0){
                    ST[c1].push_back(line[c2]);
                }
                else{
                    ST[c1].push_back(min(ST[c1-1][c2] , ST[c1-1][min(N-1 , c2 + (1 << (c1-1)))]));
                }
            }
        }
    }
};

int main()
{
    int a,b,c;
    int n,e,q;
    cin >> n;
    Tree T;
    vector<pair<int,int> > E;
    vector<int> W;
    for(int c1 = 0; c1 < n; c1++){
        vector<int> V1;
        vector<int> V2;
        T.C.push_back(V1);
        T.CW.push_back(V2);
    }

    for(int c1 = 0; c1 < n-1; c1++){
        cin >> a >> b >> c;
        T.C[a].push_back(b);
        T.C[b].push_back(a);
        T.CW[a].push_back(c);
        T.CW[b].push_back(c);
    }
    T.setup();
    cin >> e;

    for(int c1 = 0; c1 < e; c1++){
        cin >> a >> b >> c;
        E.push_back({a,b});
        W.push_back(c);
    }

    cin >> q;
    for(int c1 = 0; c1 < q; c1++){
        cin >> a >> b;
        int ans = T.dist(a,b);
        int i1,j1,i2,j2;
        if(e >= 1){
            i1 = E[0].first;
            j1 = E[0].second;
            ans = min(ans , W[0] + T.dist(a,i1) + T.dist(j1,b));
            ans = min(ans , W[0] + T.dist(a,j1) + T.dist(i1,b));
        }
        if(e == 2){
            i2 = E[1].first;
            j2 = E[1].second;
            ans = min(ans , W[1] + T.dist(a,i2) + T.dist(j2,b));
            ans = min(ans , W[1] + T.dist(a,j2) + T.dist(i2,b));
            ans = min(ans , W[0] + W[1] + T.dist(a,i1) + T.dist(j1,i2) + T.dist(j2,b));
            ans = min(ans , W[0] + W[1] + T.dist(a,i1) + T.dist(j1,j2) + T.dist(i2,b));
            ans = min(ans , W[0] + W[1] + T.dist(a,j1) + T.dist(i1,i2) + T.dist(j2,b));
            ans = min(ans , W[0] + W[1] + T.dist(a,j1) + T.dist(i1,j2) + T.dist(i2,b));
            ans = min(ans , W[0] + W[1] + T.dist(a,i2) + T.dist(j2,i1) + T.dist(j1,b));
            ans = min(ans , W[0] + W[1] + T.dist(a,i2) + T.dist(j2,j1) + T.dist(i1,b));
            ans = min(ans , W[0] + W[1] + T.dist(a,j2) + T.dist(i2,i1) + T.dist(j1,b));
            ans = min(ans , W[0] + W[1] + T.dist(a,j2) + T.dist(i2,j1) + T.dist(i1,b));
        }
        cout << ans << "\n";
    }
    return 0;
}
