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
    int n;
    cin >> n;

    vector<bool> arr(n+1, true);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (arr[i] != (i != 1)) {
            cnt++;
            for (int j = i; j <= n; j += i) {
                arr[j] = !arr[j];
            }
        }
    }

    cout << cnt << endl;

    return 0;
}

