#include <iostream>
#include <vector>
#include <algorithm>

#define rep(x,s,e) for(int x=s;x<e;x++)

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int n, m, s, p;
vvi dests;
vector<bool> snowy;

int dp[210][210][210];

int Do(int cur, int left, int prev) {
    if (cur == n)
        return 0;

    if (dp[cur][left][prev] != -1) return dp[cur][left][prev];

    int ret = 0;

    ret += dests[cur].end() - lower_bound(dests[cur].begin(), dests[cur].end(), cur - prev);

    if (!snowy[cur])
        ret += Do(cur + 1, left, prev + 1);
    else {
        int shovel = 0;
        if (left > 0)
            shovel = Do(cur + 1, left - 1, prev + 1);
        int no = Do(cur + 1, left, 0);
        ret += max(shovel, no);
    }

    return dp[cur][left][prev] = ret;
}

int main() {
    cin >> n >> m >> s >> p;

    rep(i, 0, n)
    rep(j, 0, n)
    rep(k, 0, n)
        dp[i][j][k] = -1;

    dests.resize(n);

    snowy.assign(n, false);

    rep(i, 0, m) {
        int a, b;
        cin >> a >> b;
        --a, --b;
		if (a > b) swap(a, b);
        dests[b].push_back(a);
    }

    rep(i, 0, n)
        sort(dests[i].begin(), dests[i].end());

    rep(i, 0, s) {
        int x;
        cin >> x;
        --x;
        snowy[x] = true;
    }

    int ans = Do(0, p, 0);

    cout << ans << endl;
    
    return 0;
}
