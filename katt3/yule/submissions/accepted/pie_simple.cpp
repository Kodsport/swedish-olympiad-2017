#include <bits/stdc++.h>
using namespace std;
template <class T> int size(const T &x) { return x.size(); }
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
const int INF = 2147483647;

vi primes;
ll bt(int at, ll n) {
    ll sm = n;
    rep(nxt, at, size(primes)) {
        ll n2 = n / primes[nxt] / primes[nxt];
        if (n2 == 0) break;
        sm -= bt(nxt+1, n2);
    }
    return sm;
}

int main() {
    ll n;
    cin >> n;

    ll st = 1;
    while (st * st <= n) st++;
    st += 1000;

    bool *prime = new bool[st];
    rep(i,0,st) prime[i] = true;
    for (int i = 2; i < st; i++) {
        if (prime[i]) {
            primes.push_back(i);
            for (int j = i+i; j < st; j += i) {
                prime[j] = false;
            }
        }
    }

    cout << bt(0, n) << endl;

    return 0;
}

