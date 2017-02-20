#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

signed main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int N, M;
	cin >> N >> M;
	assert(N <= 100 && M <= 100);
	map<int, int> whens;
	vector<pii> meals;
	rep(i,0,N) {
		int when, amt;
		cin >> when >> amt;
		whens[when];
		meals.emplace_back(when, amt);
	}
	int w = 0;
	trav(pa, whens) pa.second = w++;
	vi toeat(w);
	trav(meal, meals) toeat[whens[meal.first]] += meal.second;

	const int VLIM = 101;
	const int inf = 1LL << 60;
	vector<vi> bestCost(w, vi(101, inf));
	rep(i,0,M) {
		int value, cost, exp;
		cin >> value >> cost >> exp;
		auto it = whens.upper_bound(exp);
		if (it == whens.begin()) continue;
		--it;
		assert(it->first <= exp);
		exp = it->second;
		assert(value < VLIM && value > 0);
		bestCost[exp][value] = min(bestCost[exp][value], cost);
	}

	rep(i,0,w) bestCost[i][0] = 0;
	for (int i = w-2; i >= 0; --i) {
		rep(v,0,VLIM) bestCost[i][v] = min(bestCost[i][v], bestCost[i+1][v]);
	}

	vi dp(VLIM, inf), dp2;
	dp[0] = 0;
	for (int i = w-1; i >= 0; --i) {
		int cost = toeat[i];
		dp2.assign(VLIM + cost, inf);
		rep(j,0,VLIM)
			dp2[j] = dp[j];
		rep(d,0,VLIM + cost) {
			int li = VLIM + min((int)0, cost - d);
			rep(v,1,li) {
				dp2[d + v] = min(dp2[d + v], dp2[d] + bestCost[i][v]);
			}
		}
		rep(d,0,VLIM) dp[d] = dp2[d + cost];
	}
	int res = inf;
	rep(i,0,VLIM) res = min(res, dp[i]);
	assert(res != inf);
	cout << res << endl;
	exit(0);
}
