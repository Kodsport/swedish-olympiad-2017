#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int solve(vi& a, vi& b) {
	multiset<int> A(all(a));
	int res = 0;
	trav(x, b) {
		auto it = A.upper_bound(x);
		if (it == A.end()) break;
		A.erase(it);
		res++;
	}
	return res;
}

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int N, M;
	cin >> N >> M;
	vi a(N), b(M);
	rep(i,0,N) cin >> a[i];
	rep(i,0,M) cin >> b[i];
	cout << solve(a, b) + solve(b, a) << endl;
	exit(0);
}
