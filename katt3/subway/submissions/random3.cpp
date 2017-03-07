#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct iset {
	vi items;
	map<int, int> ma;
	void insert(int x) {
		ma[x] = sz(items);
		items.push_back(x);
	}
	void erase(int x) {
		int ind = ma[x];
		swap(items[ind], items.back());
		ma[items[ind]] = ind;
		items.pop_back();
		ma.erase(x);
	}
	const int* begin() const { return items.data(); }
	const int* end() const { return items.data() + sz(items); }
};

struct LinkCut {
	int n;
	vector<iset> eds;
	vi seen;
	vi stack;
	LinkCut(int N) : n(N), eds(N), seen(N) {}

	void link(int u, int v) { // add an edge (u, v)
		eds[u].insert(v);
		eds[v].insert(u);
	}

	void cut(int u, int v) { // remove an edge (u, v)
		eds[u].erase(v);
		eds[v].erase(u);
	}

	bool connected(int u, int v) { // are u, v in the same tree?
		memset(seen.data(), 0, n * sizeof(int));
		stack.clear();
		stack.push_back(u);
		while (!stack.empty()) {
			int x = stack.back();
			stack.pop_back();
			if (seen[x]++) continue;
			if (x == v) return true;
			trav(y, eds[x]) stack.push_back(y);
		}
		return false;
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
