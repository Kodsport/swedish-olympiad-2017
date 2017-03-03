#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int solvecyc(vector<vi>& ed) {
	int N = sz(ed);
	vi seen(N);
	int res = 0;
	rep(i,0,N) if (!seen[i]) {
		vi stack = {i};
		int vcount = 0, ecount = 0;
		while (!stack.empty()) {
			int x = stack.back();
			stack.pop_back();
			if (seen[x]++) continue;
			vcount++;
			trav(e, ed[x]) {
				ecount++;
				stack.push_back(e);
			}
		}
		assert(ecount % 2 == 0);
		ecount /= 2;

		if (ecount == vcount) {
			if (vcount != 1)
				res += vcount / 2 + 2;
		}
		else {
			assert(vcount == ecount + 1);
			res += vcount / 2;
		}
	}
	return res;
}

int solvetree(vector<vi>& ed, int MAX) {
	function<vi(int, int)> rec = [&](int at, int par) -> vi {
		vi res(MAX);
		int base = 0;
		trav(x, ed[at]) if (x != par) {
			vi r = rec(x, at);
			int bi = -1, v = 1 << 30, sv = v;
			rep(i,0,MAX) {
				int y = r[i];
				if (y < v) {
					sv = v;
					v = y;
					bi = i;
				} else if (y < sv) sv = y;
			}
			res[bi] += sv - v;
			base += v;
		}
		rep(i,0,MAX) res[i] += i + base;
		return res;
	};
	vi v = rec(0, -1);
	return *min_element(all(v));
}

int solvetree(vector<vi>& ed) {
	int res = solvetree(ed, 20);
	int lo = 2, hi = 20;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if (solvetree(ed, mid) == res)
			hi = mid;
		else
			lo = mid;
	}
	cerr << "need " << hi << " colors" << endl;
	return res;
}

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int N, M;
	cin >> N >> M;
	vector<vi> ed(N);
	rep(i,0,M) {
		int a, b;
		cin >> a >> b;
		ed[a].push_back(b);
		ed[b].push_back(a);
	}

	int maxdeg = 0;
	rep(i,0,N) maxdeg = max(maxdeg, sz(ed[i]));

	if (maxdeg <= 2) {
		cout << solvecyc(ed) << endl;
	}
	else {
		cout << solvetree(ed) << endl;
	}

	exit(0);
}
