#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, K;
string s;
vector<int> dp;
vector<vector<int> > cost;

void getDistances() {
    vector<bool> active(K, false);
    vector<vector<int> > dist(K, vector<int>(K, 0));
    for (int i = N - 1; i >= 0; i--) {
        int character = s[i] - 'a';
        active[character] = true;
        for (int j = 0; j < K; j++) {
            if (active[j] && character != j) {
                dist[character][j]++;
            }
        }
    }

    for (int mask = 0; mask < (1 << K); mask++) {
        for (int i = 0; i < K; i++) {
            if (mask & (1 << i)) {
                continue;
            }
            int c = 0;
            for (int j = 0; j < K; j++) {
                if (mask & (1 << j)) {
                    c += dist[j][i];
                }
            }
            cost[mask][i] = c;
        }
    }
}

int solve(int mask) {
    if (dp[mask] != -1) {
        return dp[mask];
    }
    if (mask == (1 << K) - 1) {
        return dp[mask] = 0;
    }

    int ret = 1 << 30;
    for (int i = 0; i < K; i++) {
        if (!(mask & (1 << i))) {
            int val = cost[mask][i] + solve(mask | (1 << i));
            ret = min(ret, val);
        }
    }
    return dp[mask] = ret;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    cin >> s;

    dp = vector<int>(1 << K, -1);
    cost = vector<vector<int> >(1 << K, vector<int>(K, 0));

    getDistances();
    cout << solve(0) << endl;

    return 0;
}
