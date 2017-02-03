#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define scanf nope
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef tuple<int, int, int> Finn;
typedef long double ld;

int main() {
	int N;
	cin >> N;
	map<int, vector<Finn>> finns;
	rep(i,0,N) {
		int a, b, c, t;
		cin >> a >> b >> c >> t;
		finns[-t].push_back(Finn(a, b, c));
	}
	ll A = 0, B = 0, C = 0;
	ld ans = 0;
	trav(it, finns) {
		ld t = -it.first;
		trav(it2, it.second) {
			A += get<0>(it2);
			B += get<1>(it2);
			C += get<2>(it2);
		}
		ld opt = (ld)-0.5 * B / A;
		vector<ld> attempts = {(ld)0, t};
		if (0 <= opt && opt <= t) attempts.push_back(opt);
		trav(x, attempts) {
			if (isnan(x)) continue;
			ld eval = A * x * x + B * x + C;
			ans = max(ans, eval);
		}
	}
	cout << ans << endl;
}
