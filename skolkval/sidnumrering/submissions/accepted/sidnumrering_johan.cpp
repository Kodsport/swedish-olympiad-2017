#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define V(X) vector<X>
typedef long long ll;
typedef V(ll) vi;

map<pair<int, bool>, vi> memo;

vi dig;

vi go(int at, bool follows, int last) {
	if (at == sz(dig)) {
		vi ret(11);
		ret[10] = last%2;
		return ret;
	}
	vi& ret = memo[make_pair(at, follows)];
	if (ret.empty()) {
		ret.resize(11);
		int lim = follows ? dig[at]+1 : 10;
		rep(i,0,lim) {
			vi rret = go(at + 1, follows && i == dig[at], i);
			ret[i] += rret[10];
			rep(j,0,11) ret[j] += rret[j];
		}
	}
	return ret;
}

signed main() {
	ll N;
	cin >> N;
	while(N) {
		dig.push_back(N%10);
		N /= 10;
	}
	vi ans(10);
	reverse(all(dig));

	rep(i,1,dig[0]+1) {
		vi aa = go(1, i == dig[0], i);
		aa[i] += aa.back();
		rep(j,0,10) ans[j] += aa[j];
	}
	rep(k,1,sz(dig)) {
	rep(i,1,10) {
		vi aa = go(k+1, false, i);
		aa[i] += aa.back();
		rep(j,0,10) ans[j] += aa[j];
	}
	}
	trav(it, ans) cout << it << " ";
	cout << endl;
}

