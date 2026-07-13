#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using p2 = pair<ll, ll>;
const ll inf = 1e18;

#define rep(i,n) for (ll i = 0; i < (n); i++)
#define repp(i,a,n) for (ll i = (a); i < (n); i++)
#define repe(i, arr) for (auto& i : arr)
#define all(x) begin(x),end(x)
#define sz(x) ((ll)(x).size())

using vvvi = vector<vvi>;
ll ans(vector<vvvi>& memo, vi& digits, ll desired, ll index, ll n, bool unlimited, bool nonzero) {
    if (index==-1) return n;

    ll& v = memo[index][n][unlimited][nonzero];

    if (v != -1) return v;

    ll ret = 0;

    ll limit = unlimited ? 10 : digits[index] + 1;
    rep(i, limit) {
        if (index==0&&i%2==0) {
            continue;
        }
        ret += ans(memo, digits, desired, index - 1, n + (ll)(i == desired && (i>0||nonzero)), unlimited || (i < digits[index]), nonzero || (i > 0));
    }

    return (v=ret);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;

    string nstr = to_string(n);
    vi digits(nstr.size());
    rep(i, nstr.size())
    {
        digits[i] = nstr[i] - '0';
    }
    reverse(all(digits));

    rep(i, 10) {
        vector<vvvi> memo(20, vvvi(20, vvi(2, vi(2, -1))));
        cout << ans(memo, digits, i, digits.size() - 1, 0, false, false) << " ";
    }
    
    return 0;
}
