#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define scanf nope
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int N, K;
	cin >> N >> K;

	string S;
	cin >> S;
	vi has(K);

	vector<vi> needs(K);
	rep(i,0,sz(S)) {
		has[S[i] - 'a']++;
		needs[S[i] - 'a'] = has;
	}

	const int INF = 1000000000;
	vi ans(1 << K, INF);
	ans[0] = 0;

	rep(i,0,1<<K) {
		rep(j,0,K) {
			if (i & (1 << j)) continue;
			int cost = 0;
			rep(k,0,K) {
				if (i & (1 << k)) cost += needs[j][k];
			}
			ans[i|(1 << j)] = min(ans[i|(1<<j)], ans[i] + cost);
		}
	}

	cout << ans.back() << endl;
}
