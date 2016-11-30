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

//Should work if a_i = 1

int main(){
    int n, m, s, p;
    cin >> n >> m >> s >> p;
    vector<int> a(m), b(m);
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
    sort(snow.begin(), snow.end());
    /*Skottar bort de p första högarna, dvs fram till snow[p-1].
    Nästa snöhög, snow[p] blir då den första snön som blockar.
    Eftersom alla börjar på första stationen,
    så kan precis de som slutar före eller på station snow[p] åka.
    Så vi räknar dem */
    int ans = 0;
    rep(i, 0, m) {
        if(b[i] <= snow[p]) ans++;
    }
    cout << ans << endl;
    return 0;
}