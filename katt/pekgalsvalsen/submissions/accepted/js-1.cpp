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

	vi order(K);
	rep(i,0,K) order[i] = i;

	auto compute = [&](int has, int add) {
		int res = 0;
		int len = 0;
		trav(it, S) {
			if (has&(1 << (it - 'a'))) len++;
			if (it - 'a' == add) res = len;
		}
		return res;
	};

	assert(K == 2);

	int ans = 1<<30;
	do {
		int cost = 0;
		int cov = 0;
		rep(w,0,K) {
			int i = order[w];
			cost += compute(cov, i);
			cov |= 1<<i;
		}
		ans = min(ans, cost);
	} while(next_permutation(all(order)));
	cout << ans << endl;
}
