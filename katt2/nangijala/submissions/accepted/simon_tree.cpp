#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int solvetree(vector<vi>& ed) {
	int MAX = 20;
	int itcount = 0, N = sz(ed);
	function<vi(int, int)> rec = [&](int at, int par) -> vi {
		if (++itcount > N) throw 0;
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

	cout << solvetree(ed) << endl;

	exit(0);
}
