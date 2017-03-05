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

int main() {
    ll n;
    cin >> n;

    ll to = 1;
    while (to*to <= n) to++;

    int *mob = new int[to+1];
    bool *prime = new bool[to+1];
    rep(i,0,to+1) {
        mob[i] = 1;
        prime[i] = true;
    }
    for (int i = 2; i <= to; i++) {
        if (prime[i]) {
            for (int j = i; j <= to; j += i) {
                prime[j] = false;
                mob[j] = -mob[j];
                if ((j/i)%i == 0) {
                    mob[j] = 0;
                }
            }
        }
    }

    ll cnt = 0;
    for (ll i = 1; i*i <= n; i++) {
        cnt += mob[i] * (n / i / i);
    }
    cout << cnt << endl;

    return 0;
}

