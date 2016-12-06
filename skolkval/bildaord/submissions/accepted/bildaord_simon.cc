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
	int N, M;
	cout << "Antal bokstäver ? "; cin >> N;
	cout << "Antal regler ? "; cin >> M;

	vi any(N+1); iota(all(any), 0);
	vector<vi> allowed(N, vi(N, 1)), after(N, any);

	rep(it,0,M) {
		string str;
		cout << "Regel " << it+1 << " ? "; cin >> str;
		int letter = str[0] - 'A';
		if (str[1] == ':') {
			after[letter].clear();
			trav(c, str.substr(2))
				after[letter].push_back(c - 'A');
		}
		else {
			allowed[letter].assign(N, 0);
			for (int j = 2; j < sz(str); j += 3) {
				int pos = (str[j] - '0') * 10 + (str[j+1] - '0') - 1;
				allowed[letter][pos] = 1;
			}
		}
	}

	int res = 0;
	vi used(N+1); used[N] = 1;
	// string str;
	function<void(int, const vi&)> rec = [&](int pos, const vi& cand) {
		if (pos == N) {
			if (sz(cand) == N+1) {
				// cout << str << endl;
				res++;
			}
			return;
		}
		trav(c, cand) {
			if (used[c] || !allowed[c][pos]) continue;
			used[c] = 1;
			// str += (char)('A' + c);
			rec(pos+1, after[c]);
			// str.pop_back();
			used[c] = 0;
		}
	};
	rec(0, any);
	cout << res << endl;
	exit(0);
}
