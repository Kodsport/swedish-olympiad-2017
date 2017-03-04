#include <bits/stdc++.h>
using namespace std;

#define rep(x,s,e) for(int x=(int)s;x<(int)e;x++)

typedef vector<int> vi;
typedef vector<vi>  vvi;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<bool> vb;
const int INF = (int)2e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    if(n > 1000 || m > 4000)
        return 0;

    vi height(n);
    rep(i, 0, n) {
        cin >> height[i];
    }

    vvi e(n);
    rep(i, 0, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;

        e[a].push_back(b);
        e[b].push_back(a);
    }

    rep(s, 0, n) {
        priority_queue<pii, vpii, greater<pii>> q;
        vb done(n, false);
        vi ans(n, -1);

        bool foundHigher = false;

        q.push({0, s});
        ans[s] = 0;
        
        while (!q.empty()) {
            int cur = q.top().second;
            q.pop();

            if (done[cur])
                continue;
            else
                done[cur] = true;

            if (height[cur] > height[s]) {
                cout << ans[cur] << " ";
                foundHigher = true;
                break;
            }


            for (int u : e[cur]) {
                int newAns = max(ans[cur], height[s] - height[u]);
                if (newAns < ans[u] || ans[u] == -1) {
                    ans[u] = newAns;
                    q.push({newAns, u});
                }
            }
        }

        if (!foundHigher)
            cout << height[s] << " ";
    }

    cout << endl;
    
    return 0;
}