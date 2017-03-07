#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int N;
	cin >> N;

	if (N == 1) {
		cout << 0 << endl;
		return 0;
	}

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
		sourcel.pop_back();
		targetl.pop_back();
		out.emplace_back(i,j,i2,j2);
	}

	cout << sz(out) << endl;
	trav(t, out) {
		int a,b,c,d;
		tie(a,b,c,d) = t;
		cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
	}
	assert(sz(out) == delta);
}
