#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct UF {
	vi v;
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

struct LinkCut {
	int n;
	set<pii> eds;
	UF uf;
	LinkCut(int N) : n(N), uf(N) {}

	void link(int u, int v) { // add an edge (u, v)
		eds.insert(pii(u, v));
	}

	void cut(int u, int v) { // remove an edge (u, v)
		eds.erase(pii(u, v));
	}

	bool connected(int u, int v) { // are u, v in the same tree?
		memset(uf.v.data(), -1, n * sizeof(int));
		trav(e, eds) uf.join(e.first, e.second);
		return uf.find(u) == uf.find(v);
	}
};

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int N;
	cin >> N;

	if (N == 1) {
		cout << 0 << endl;
		return 0;
	}

	LinkCut lc(N);

	int u, v;
	set<pii> source, target;
	rep(i,0,N-1) {
		cin >> u >> v;
		if (u > v) swap(u, v);
		source.insert(pii(u,v));
		lc.link(u, v);
	}
	rep(i,0,N-1) {
		cin >> u >> v;
		if (u > v) swap(u, v);
		if (source.count(pii(u,v)))
			source.erase(pii(u,v));
		else
			target.insert(pii(u,v));
	}

	int delta = sz(source);
	assert(delta == sz(target));

	vector<pii> sourcel(all(source)), targetl(all(target));

	vector<tuple<int, int, int, int>> out;
	while (!sourcel.empty()) {
		int i = rand() % sz(sourcel);
		int j = rand() % sz(sourcel);
		swap(sourcel[i], sourcel.back());
		swap(targetl[j], targetl.back());
		int i2, j2;
		tie(i,j) = sourcel.back();
		tie(i2,j2) = targetl.back();
		lc.cut(i, j);
		if (lc.connected(i2,j2)) {
			lc.link(i, j);
		} else {
			lc.link(i2,j2);
			sourcel.pop_back();
			targetl.pop_back();
			out.emplace_back(i,j,i2,j2);
		}
	}

	cout << sz(out) << endl;
	trav(t, out) {
		int a,b,c,d;
		tie(a,b,c,d) = t;
		cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
	}
	assert(sz(out) == delta);
}
