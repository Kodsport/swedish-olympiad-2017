#include <bits/stdc++.h>
using namespace std;

#define rep(x,s,e) for(int x=(int)s;x<(int)e;x++)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

vi d;

vi ds;
vi de;
vi kl;

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    d.assign(n, 0);    
    rep(i, 0, n - 1) {
        int a, b, l;
        cin >> a >> b >> l;        
        assert(a == i && b == i + 1);
        d[i + 1] = d[i] + l;
    }

    int e;
    cin >> e;
    rep(i, 0, e) {
        int a, b, l;
        cin >> a >> b >> l;
        ds.push_back(d[a]);
        de.push_back(d[b]);
        kl.push_back(l);
    }

    int q;
    cin >> q;
    rep(query, 0, q) {
        int a, b;
        cin >> a >> b;

        int ret = abs(d[a] - d[b]);
        rep(i, 0, e) {
            ret = min(ret, abs(d[a] - ds[i]) + kl[i] + abs(de[i] - d[b]));
            ret = min(ret, abs(d[a] - de[i]) + kl[i] + abs(ds[i] - d[b]));
        }
        if (e == 2) {
            ret = min(ret, abs(d[a] - ds[0]) + kl[0] + abs(de[0] - ds[1]) + kl[1] + abs(de[1] - d[b]));
            ret = min(ret, abs(d[a] - ds[0]) + kl[0] + abs(de[0] - de[1]) + kl[1] + abs(ds[1] - d[b]));
            ret = min(ret, abs(d[a] - de[0]) + kl[0] + abs(ds[0] - ds[1]) + kl[1] + abs(de[1] - d[b]));            
            ret = min(ret, abs(d[a] - de[0]) + kl[0] + abs(ds[0] - de[1]) + kl[1] + abs(ds[1] - d[b]));

            ret = min(ret, abs(d[a] - ds[1]) + kl[1] + abs(de[1] - ds[0]) + kl[0] + abs(de[0] - d[b]));
            ret = min(ret, abs(d[a] - ds[1]) + kl[1] + abs(de[1] - de[0]) + kl[0] + abs(ds[0] - d[b]));
            ret = min(ret, abs(d[a] - de[1]) + kl[1] + abs(ds[1] - ds[0]) + kl[0] + abs(de[0] - d[b]));            
            ret = min(ret, abs(d[a] - de[1]) + kl[1] + abs(ds[1] - de[0]) + kl[0] + abs(ds[0] - d[b]));                        
        }

        cout << ret << endl;
    }

    return 0;
}