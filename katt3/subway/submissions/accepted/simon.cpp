#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Edge {
	int u, v, id;
};

struct UF {
	vi v, deg;
	vector<vector<Edge>> ed, ed2;
	UF(int n) : v(n, -1), deg(n), ed(n), ed2(n) {}
	int find(int x) { return v[x] < 0 ? x : v[x] = find(v[x]); }
	void join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (-v[a] < -v[b]) swap(a, b);
		v[a] += v[b];
		deg[a] += deg[b];
		ed[a].insert(ed[a].end(), all(ed[b]));
		ed2[a].insert(ed2[a].end(), all(ed2[b]));
		v[b] = a;
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

	UF uf(N);

	int u, v;
	set<pii> source, target;
	rep(i,0,N-1) {
		cin >> u >> v;
		if (u > v) swap(u, v);
		source.insert(pii(u,v));
	}
	rep(i,0,N-1) {
		cin >> u >> v;
		if (u > v) swap(u, v);
		if (source.count(pii(u,v))) {
			uf.join(u, v);
			source.erase(pii(u,v));
		}
		else
			target.insert(pii(u,v));
	}

	int delta = sz(source);
	assert(delta == sz(target));

	vector<bool> dead;
	int eid = 0;
	trav(e, source) {
		tie(u,v) = e;
		Edge edg = {u, v, eid++};
		uf.ed[uf.find(u)].push_back(edg);
		uf.ed[uf.find(v)].push_back(edg);
		dead.push_back(false);
	}
	trav(e, target) {
		tie(u,v) = e;
		Edge edg = {u, v, eid++};
		uf.ed2[uf.find(u)].push_back(edg);
		uf.ed2[uf.find(v)].push_back(edg);
		dead.push_back(false);
	}

	vi leaves;
	rep(i,0,N) {
		uf.deg[i] = sz(uf.ed[i]);
		if (uf.deg[i] == 1) leaves.push_back(i);
	}

	vector<tuple<int, int, int, int>> out;
	while (!leaves.empty()) {
		int theLeaf = leaves.back();
		int comp = uf.find(theLeaf);
		leaves.pop_back();

		if (uf.ed[comp].empty()) continue;
		Edge e = uf.ed[comp].back(), e2;
		uf.ed[comp].pop_back();
		if (dead[e.id]) {
			leaves.push_back(theLeaf);
			continue;
		}

		int x = e.u, y = e.v;
		if (uf.find(x) != comp) swap(x, y);
		assert(uf.find(x) == comp);

		// Remove the edge (x, y), and find some (x2, y2) adjacent to
		// the same component to replace it by.
		for (;;) {
			assert(uf.ed2[comp].size() >= 1);
			e2 = uf.ed2[comp].back();
			uf.ed2[comp].pop_back();
			if (!dead[e2.id]) break;
		}

		int x2 = e2.u, y2 = e2.v;
		if (uf.find(x2) != comp) swap(x2, y2);
		assert(uf.find(x2) == comp);

		out.emplace_back(x, y, x2, y2);
		dead[e.id] = true;
		dead[e2.id] = true;
		--uf.deg[comp];
		if (--uf.deg[uf.find(y)] == 1) {
			leaves.push_back(y);
		}
		uf.join(x, y2);
	}

	cout << sz(out) << endl;
	trav(t, out) {
		int a,b,c,d;
		tie(a,b,c,d) = t;
		cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
	}
	assert(sz(out) == delta);
}
