#include <iostream>
#include <vector>
using namespace std;

vector<bool> visited;
vector<vector<int> > e;

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

pair<int, bool> solveTree(int node) {
    if (visited[node]) {
        return make_pair(0, false);
    }
    visited[node] = true;
    int ret = 0;
    bool dead = false;
    for (int next : e[node]) {
        pair<int, bool> res = solveTree(next);
        ret += res.first;
        dead |= res.second;
    }
    if (dead) {
        ret++;
    }
    return make_pair(ret, !dead);
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    visited = vector<bool>(n, false);
    e = vector<vector<int> >(n, vector<int>());
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    vector<vector<int> > deg(3, vector<int>());
    for (int i = 0; i < n; i++) {
        deg[e[i].size()].push_back(i);
    }

    int ans = 0;
    for (int root : deg[2]) {
        if (!visited[root]) {
            ans += solveTree(root).first;
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
