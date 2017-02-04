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
	int N, L, M;
	cin >> N >> L >> M;
	vi start(L);
	rep(i,0,L) cin >> start[i];
	vector<vector<tuple<int, int, int>>> ed(N);
	rep(i,0,M) {
		int a, b, w;
		cin >> a >> b >> w;
		ed[a].emplace_back(b, w, i);
		ed[b].emplace_back(a, w, i);
	}

	set<pii> fights;
	auto addf = [&](int a, int b) {
		assert(a != b);
		if (a > b) swap(a, b);
		fights.insert(pii(a, b));
	};

	map<int, vector<tuple<int, int, int>>> q;
	rep(i,0,L) {
		q[0].emplace_back(i, start[i], -1);
	}


	vector<set<int>> vfights(N);
	vi ate(M, -1);
	trav(pa1, q) {
		int time = pa1.first;
		vector<tuple<int, int, int>> &evs = pa1.second, added;
		int who, where, how;
		trav(pa, evs) {
			tie(who, where, how) = pa;
			if (how != -1 && ate[how] == -2) continue;
			if (vfights[where].count(who)) continue;
			trav(x, vfights[where]) {
				addf(who, x);
			}
			vfights[where].insert(who);
			added.push_back(pa);
		}

		trav(pa, added) {
			tie(who, where, how) = pa;
			assert(vfights[where].size() == 1); // no node wars!
			if (vfights[where].size() == 1) {
				// We own this place, go on.
				trav(e, ed[where]) {
					int to, w, ind;
					tie(to, w, ind) = e;
					assert(ate[ind] != -2);
					if (ate[ind] != -1) {
						if (ate[ind] != who) addf(ate[ind], who);
						ate[ind] = -2;
						continue;
					}
					ate[ind] = who;
					int time2 = time + w;
					q[time2].emplace_back(who, to, ind);
				}
			}
		}
	}

	trav(pa, fights) {
		cout << pa.first << ' ' << pa.second << endl;
	}

	exit(0);
}
