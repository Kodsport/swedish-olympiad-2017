#include <iostream>
#include <vector>
using namespace std;

const int MAX_COLORS = 20;

vector<bool> visited;
vector<int> par;
vector<vector<int> > e;
vector<vector<int> > dp;

int componentSize(int node) {
    if (visited[node]) {
        return 0;
    }
    visited[node] = true;
    int ret = 1;
    for (int next : e[node]) {
        ret += componentSize(next);
    }
    return ret;
}

void generateParents(int node) {
    visited[node] = true;
    for (int next : e[node]) {
        if (!visited[next]) {
            par[next] = node;
            generateParents(next);
        }
    }
}

int solveTree(int node, int lastColor) {
    if (dp[node][lastColor] != -1) {
        return dp[node][lastColor];
    }
    int ret = 1 << 30;
    for (int i = 0; i < MAX_COLORS; i++) {
        if (i == lastColor) {
            continue;
        }
        int res = i;
        for (int next : e[node]) {
            if (next != par[node]) {
                res += solveTree(next, i);
            }
        }
        ret = min(ret, res);
    }
    return dp[node][lastColor] = ret;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    visited = vector<bool>(n, false);
    dp = vector<vector<int> >(n, vector<int>(MAX_COLORS+1, -1));
    e = vector<vector<int> >(n, vector<int>());
    par = vector<int>(n, -1);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    vector<vector<int> > deg(3, vector<int>());
    for (int i = 0; i < n; i++) {
        int d = min(2, (int)e[i].size() - 1);
        deg[d].push_back(i);
    }

    int ans = 0;
    for (int root : deg[2]) {
        if (!visited[root]) {
            generateParents(root);
            ans += solveTree(root, MAX_COLORS);
        }
    }
    for (int node : deg[0]) {
        if (!visited[node]) {
            ans += componentSize(node) / 2;
        }
    }
    for (int node : deg[1]) {
        if (!visited[node]) {
            int compSize = componentSize(node);
            if (compSize & 1) {
                ans += (compSize / 2) + 2;
            } else {
                ans += compSize / 2;
            }
        }
    }

    cout << ans << endl;
}
