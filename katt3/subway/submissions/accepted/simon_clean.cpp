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

	vector<bool> dead(delta * 2);
	int eid = 0;
	trav(e, source) {
		tie(u,v) = e;
		uf.ed[uf.find(u)].push_back({u, v, eid});
		uf.ed[uf.find(v)].push_back({v, u, eid++});
	}
	trav(e, target) {
		tie(u,v) = e;
		uf.ed2[uf.find(u)].push_back({u, v, eid});
		uf.ed2[uf.find(v)].push_back({v, u, eid++});
	}

	vi leaves;
	rep(i,0,N) {
		uf.deg[i] = sz(uf.ed[i]);
		if (uf.deg[i] == 1) leaves.push_back(i);
	}

	auto pop_edge = [&](vector<Edge>& ed, int* x, int* y) -> bool {
		while (!ed.empty()) {
			Edge e = ed.back();
			ed.pop_back();
			if (!dead[e.id]) {
				*x = e.u;
				*y = e.v;
				dead[e.id] = true;
				return true;
			}
		}
		return false;
	};

	cout << delta << endl;
	while (!leaves.empty()) {
		int comp = uf.find(leaves.back());
		leaves.pop_back();

		int x, y, x2, y2;
		if (!pop_edge(uf.ed[comp], &x, &y)) continue;
		bool r = pop_edge(uf.ed2[comp], &x2, &y2);
		assert(r);
		assert(uf.find(x) == comp);
		assert(uf.find(x2) == comp);

		cout << x << ' ' << y << ' ' << x2 << ' ' << y2 << endl;
		delta--;

		--uf.deg[comp];
		if (--uf.deg[uf.find(y)] == 1)
			leaves.push_back(y);
		uf.join(x, y2);
	}
	assert(!delta);
}
