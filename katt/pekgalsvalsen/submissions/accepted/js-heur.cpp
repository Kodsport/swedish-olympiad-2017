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

	vi order(K);
	rep(i,0,K) order[i] = i;

	auto compute = [&](int i, int j) {
		int cost = 0;
		rep(k,0,K) {
			if (i & (1 << k)) cost += needs[j][k];
		}
		return cost;
	};


	int ans = 1<<30;
	rep(i,0,1000000) {
		int cost = 0;
		int cov = 0;
		rep(w,0,K) {
			int i = order[w];
			cost += compute(cov, i);
			cov |= 1<<i;
		}
		ans = min(ans, cost);
		random_shuffle(all(order));
	} 
	cout << ans << endl;
}
