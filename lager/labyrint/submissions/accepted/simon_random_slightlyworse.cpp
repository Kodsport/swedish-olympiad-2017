#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int tr(char c) {
	if (c == 'R') return 0;
	if (c == 'G') return 1;
	if (c == 'B') return 2;
	assert(0);
}

void nextsize(int* n) {
	*n += 2;
	if (*n >= 1000) {
		*n += (int)sqrt(*n);
		*n &= -2;
	}
}

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	string s_;
	cin >> s_;
	vi s, s2;
	trav(c,s_) s.push_back(tr(c));

	trav(t, s) {
		if (!s2.empty() && s2.back() == t) s2.pop_back();
		else s2.push_back(t);
	}
	vi init;
	while (s2.size() >= 2 && s2.front() == s2.back()) {
		init.push_back(s2.front());
		s2.pop_back();
		s2.erase(s2.begin());
	}
	reverse(all(init));

	if (sz(s2) == 1) {
		s.reserve(s.size() * 2);
		s.insert(s.end(), s.begin(), s.end());
		init.clear();
		s2.clear();
	}

	int successes = 0;
	for (int n = 2;; nextsize(&n)) { // (could retry several times)
		array<int, 3> nothing = {{-1,-1,-1}};
		vector<array<int, 3>> ed(n, nothing);
		vector<int> remaining[3];
		rep(j,0,3) {
			rep(i,0,n-1) remaining[j].push_back(i);
			random_shuffle(all(remaining[j]));
		}

		int at = 0;
		auto walk = [&](int c, bool last) -> bool {
			if (ed[at][c] == -1) {
				int at2;
				if (last && at != 0 && ed[0][c] == -1)
					at2 = 0;
				else do {
					if (remaining[c].empty()) return false;
					at2 = remaining[c].back();
					remaining[c].pop_back();
				} while (at2 == at || ed[at2][c] != -1);
				assert(at != at2);
				assert(ed[at][c] == -1);
				assert(ed[at2][c] == -1);
				ed[at][c] = at2;
				ed[at2][c] = at;
			}
			at = ed[at][c];
			assert(at != n-1);
			return true;
		};
		auto walk2 = [&](int c) {
			assert(ed[at][c] != -1);
			assert(at != n-1);
			at = ed[at][c];
		};

		rep(i,0,sz(s2)) {
			bool last = (i == sz(s2)-1);
			if (!walk(s2[i], last)) goto fail;
		}
		if (at == 0) {
			trav(c, init) if (!walk(c, false)) goto fail;
			int at1 = at;
			trav(c, s) if (!walk(c, false)) goto fail;
			assert(at == at1);
			trav(c, s) walk2(c);
			assert(at == at1);
			rep(j,0,3) {
				remaining[j].push_back(n-1);
				int last = -1;
				trav(x, remaining[j]) if (ed[x][j] == -1) {
					if (last == -1) last = x;
					else {
						ed[x][j] = last;
						ed[last][j] = x;
						last = -1;
					}
				}
				assert(last == -1);
			}

			vi seen(n);
			vi stack = {0};
			while (!stack.empty()) {
				int ind = stack.back();
				stack.pop_back();
				if (seen[ind]++) continue;
				rep(j,0,3) stack.push_back(ed[ind][j]);
			}
			rep(i,0,n) if (!seen[i]) goto fail;

			if (++successes == 2) {
				cout << n << ' ' << at1 << ' ' << n-1 << endl;
				rep(i,0,n) {
					rep(j,0,3) cout << ed[i][j] << ' ';
					cout << endl;
				}
				return 0;
			}
		}
fail:;
	}
	exit(0);
}
