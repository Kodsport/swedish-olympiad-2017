#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
typedef pair<int, int> pii;
typedef long long ll;

struct UF {
	vector<int> v;
	UF(int n) : v(n, -1) {}
	int find(int x) { return v[x] < 0 ? x : v[x] = find(v[x]); }
	void join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (-v[a] < -v[b]) swap(a, b);
		v[a] += v[b];
		v[b] = a;
	}
};


int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int N;
	cin >> N;
	vector<ll> cost(N);
	rep(i,0,N) cin >> cost[i];
	vector<vector<ll>> mat(N, vector<ll>(N));
	rep(i,0,N) rep(j,0,N) cin >> mat[i][j];

	vector<pair<ll, pii>> ed(N+1);
	rep(i,0,N) rep(j,0,N) {
		ed.emplace_back(mat[i][j], pii(i,j));
	}
	rep(i,0,N) ed.emplace_back(cost[i], pii(N, i));

	UF uf(N+1);
	sort(all(ed));
	ll res = 0;
	trav(e, ed) {
		int a = e.second.first, b = e.second.second;
		if (uf.find(a) != uf.find(b)) {
			res += e.first;
			uf.join(a, b);
		}
	}

	cout << res << endl;
	exit(0);
}
