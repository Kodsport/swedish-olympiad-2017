#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>

using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)

typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pii;
typedef long long ll;

//m*s*2^s!
//Should work for s <= 12 and p = 1, if m and n are small

int main(){
    int n, m, s, p;
    cin >> n >> m >> s >> p;
    vector<int> a(m), b(n);
    rep(i, 0, m) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        if(a[i] > b[i]) swap(a[i], b[i]);
    }
    vector<int> snow(s);
    rep(i, 0, s) {
        cin >> snow[i];
        snow[i]--;
    }
    if(p >= s) {
        cout << m << endl;
        return 0;
    }
    vector<bool> skotta(s, true);
    rep(i, 0, s-p) skotta[i] = false;
    int ans = 0;
    do {
        int tempans = m;
        rep(i, 0, m) {
            rep(j, 0, s) {
                if(skotta[j]) continue;
                if(snow[j] >= a[i] && snow[j] < b[i]) tempans--;
            }
        }
        ans = max(ans, tempans);   
    } while(next_permutation(skotta.begin(), skotta.end()));
    cout << ans << endl;
}