#include <bits/stdc++.h>

using namespace std;

int n,m;

vector<int> H;
vector<int> PF;
vector<int> ind;
vector<vector<int> > C(100001 , vector<int>());

bool mark[100001] = {0};

struct UF{

    vector<int> pek;
    vector<int> deg;
    vector<vector<int> > maxh;

    UF(int i){
        for(int c1 = 0; c1 < i; c1++){
            pek.push_back(c1);
            vector<int> temp;
            temp.push_back(c1);
            maxh.push_back(temp);
            deg.push_back(1);
        }
    }

    int parent(int i){
        int i2 = pek[i];
        while(i2 != pek[i2])i2 = pek[i2];
        return i2;
    }

    void merg(int i , int j, int lowpoint){

        int i2 = parent(i);
        int j2 = parent(j);
        if(i2 != j2){

            if(deg[i2] < deg[j2]){
                int temp = i2;
                i2 = j2;
                j2 = temp;
            }
            deg[i2] += deg[j2];
            pek[j2] = i2;

            if(H[maxh[i2][0]] == H[maxh[j2][0]]){
                for(int c1 = 0; c1 < maxh[j2].size(); c1++){
                    maxh[i2].push_back(maxh[j2][c1]);
                }
                maxh[j2].clear();
            }
            else{
                int k = j2;
                if(H[maxh[i2][0]] < H[maxh[j2][0]])k = i2;
                for(int c1 = 0; c1 < maxh[k].size(); c1++){
                    PF[maxh[k][c1]] = H[maxh[k][c1]] - lowpoint;
                }

                if(k == i2){
                    maxh[i2].clear();
                    for(int c1 = 0; c1 < maxh[j2].size(); c1++){
                        maxh[i2].push_back(maxh[j2][c1]);
                    }
                }
            }
        }
    }
};

bool comp(int i , int j){
return H[i] > H[j];
}

int main()
{
    int a,b,c;
    cin >> n >> m;
    UF uf(n);
    for(int c1 = 0; c1 < n; c1++){
        cin >> a;
        H.push_back(a);
        PF.push_back(a);
        ind.push_back(c1);
    }
    for(int c1 = 0; c1 < m; c1++){
        cin >> a >> b;
        a--;
        b--;
        C[a].push_back(b);
        C[b].push_back(a);
    }

    sort(ind.begin() , ind.end() , comp);

    for(int c1 = 0; c1 < n; c1++){
        a = ind[c1];
        for(int c2 = 0; c2 < C[a].size(); c2++){
            b = C[a][c2];
            if(mark[b] == 1){
                uf.merg(a,b,H[a]);
            }
        }
        mark[a] = 1;
    }

    for(int c1 = 0; c1 < n; c1++){
        cout << PF[c1] << " ";
    }

    cout << endl;

    return 0;
}
