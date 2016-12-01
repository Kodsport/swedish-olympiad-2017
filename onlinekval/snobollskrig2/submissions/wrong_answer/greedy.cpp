#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void throww(multiset<int>& a, multiset<int>& b) {
	int at = -1;
	bool which = false;
	while(true) {
		if (!which) {
			auto nx = a.lower_bound(at+1);
			if (nx == a.end()) break;
			at = *nx;
			a.erase(nx);
		} else {
			auto nx = b.lower_bound(at+1);
			if (nx == b.end()) break;
			at = *nx;
			b.erase(nx);
		}
		which = !which;
	}
}

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int N, M;
	cin >> N >> M;
	vi a(N), b(M);
	rep(i,0,N) cin >> a[i];
	rep(i,0,M) cin >> b[i];
	multiset<int> A(all(a)), B(all(b));
	int res = 0;
	while (sz(A) || sz(B)) {
		if (sz(A) < sz(B)) swap(A, B);
		throww(A, B);
		res++;
	}
	res += sz(A);
	res += sz(B);
	cout << N+M-res << endl;
}
