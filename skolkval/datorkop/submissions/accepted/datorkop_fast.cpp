// Binary search the value C that Klara's department gets, over the values a department
// can actually have. Leftover computers can always be dumped on the most important
// department, so C is reachable exactly when all n departments can be given value >= C.
//
// Relabel so that the laptop is the pricier computer. A department that takes j laptops
// then needs ceil((C - j*b) / a) desktops, and it never pays to give it more than
// ceil(C / b) laptops. Since C * n <= x*a + y*b for any reachable C, that leaves only
// about (x + y) / n useful values of j, so
//     dp[j] = fewest desktops needed to serve t departments with exactly j laptops
// costs O(y * (x + y)) per check no matter how large n is.
#include <bits/stdc++.h>
using namespace std;

int x, a, y, b, n, V;

bool feasible(int C) {
    if (C == 0) return true;
    if ((long long)C * n > V) return false;

    int jmax = min(y, (C + b - 1) / b);
    vector<int> need(jmax + 1);
    for (int j = 0; j <= jmax; j++) {
        int rest = C - j * b;
        need[j] = rest <= 0 ? 0 : (rest + a - 1) / a;
    }

    const int INF = x + 1;  // anything above x is just as unusable
    vector<int> dp(y + 1, INF), nxt(y + 1);
    dp[0] = 0;
    for (int t = 0; t < n; t++) {
        fill(nxt.begin(), nxt.end(), INF);
        for (int j = 0; j <= y; j++) {
            if (dp[j] == INF) continue;
            for (int k = 0; k <= jmax && j + k <= y; k++)
                nxt[j + k] = min(nxt[j + k], min(INF, dp[j] + need[k]));
        }
        dp.swap(nxt);
    }
    return *min_element(dp.begin(), dp.end()) <= x;
}

int main() {
    if (scanf("%d %d %d %d %d", &x, &a, &y, &b, &n) != 5) return 1;
    if (a > b) { swap(x, y); swap(a, b); }
    V = x * a + y * b;

    vector<char> reachable(V + 1, 0);
    for (int i = 0; i <= x; i++)
        for (int j = 0; j <= y; j++)
            reachable[i * a + j * b] = 1;
    vector<int> cand;
    for (int v = 0; v <= V; v++)
        if (reachable[v]) cand.push_back(v);

    int lo = 0, hi = cand.size() - 1;  // cand[0] == 0, always feasible
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (feasible(cand[mid])) lo = mid; else hi = mid - 1;
    }
    printf("%d\n", cand[lo]);
}
