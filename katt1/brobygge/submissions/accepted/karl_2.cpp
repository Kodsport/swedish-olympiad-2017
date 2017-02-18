#include <bits/stdc++.h>
using namespace std;

#define rep(x,s,e) for(int x=(int)s;x<(int)e;x++)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

int n;

vvpii e;
vi par;
vi len;
vi level;

vvpii dp;

void root(int cur, int prev, int lev) {
    for (pii& u : e[cur]) {
        if (u.first != prev) {
            par[u.first] = cur;
            len[u.first] = u.second;
            level[u.first] = lev + 1;
            root(u.first, cur, lev + 1);
        }
    }
}

void build() {
    dp.resize(17);
    for(auto& v : dp)
        v.resize(n);

    //1st ancestor of node i is par[i], with dist len[i] from i
    rep(i, 0, n) {
        dp[0][i] = {par[i], len[i]};
    }

    //bottom up dp, 2^i-th ancestor
    rep(j, 1, dp.size()) {
        rep(i, 0, n) {
            dp[j][i] = {dp[j-1][dp[j-1][i].first].first, dp[j-1][i].second + dp[j-1][dp[j-1][i].first].second};
        }
    }
}

int dist(int a, int b) {
    //make sure a is lower than b
    if (level[a] < level[b])
        swap(a, b);

    int ret = 0;

    //move a up to the same level as b
    int steps = level[a] - level[b];
    rep(i, 0, 17) {
        if ((1 << i) & steps) {
            ret += dp[i][a].second;
            a = dp[i][a].first;
        }
    }

    if (a != b) {
        //move both as far as possible up without meeting
        for(int i = 17 - 1; i >= 0; i--) {
            if (dp[i][a].first != dp[i][b].first) {
                ret += dp[i][a].second + dp[i][b].second;
                a = dp[i][a].first;
                b = dp[i][b].first;
            }
        }

        //walk last step if
        ret += dp[0][a].second + dp[0][b].second;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;

    e.resize(n);    
    rep(i, 0, n - 1) {
        int a, b, l;
        cin >> a >> b >> l;
        e[a].push_back({b, l});
        e[b].push_back({a, l});
    }

    par.assign(n, 0);
    len.assign(n, 0);
    level.assign(n, 0);
    root(0, 0, 0);

    build();

    int extra;
    cin >> extra;
    assert(extra == 0);

    int q;
    cin >> q;
    rep(query, 0, q) {
        int a, b;
        cin >> a >> b;
        cout << dist(a, b) << endl;
    }

    return 0;
}