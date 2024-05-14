#include <bits/stdc++.h>
using namespace std;

// #undef _GLIBCXX_DEBUG                // disable run-time bound checking, etc
// #pragma GCC optimize("Ofast,inline") // Ofast = O3,fast-math,allow-store-data-races,no-protect-parens
// #pragma GCC optimize ("unroll-loops")


#define ll long long
#define INF (ll)1e9+7
#define fo(i, n) for(int i=0;i<(int)n;i++)
#define Fo(i, k, n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define LSOne(S) ((S) & (-S))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<vpii> vvpii;
typedef vector<vpl> vvpl;

int a, b;

map<tuple<int, int, int, int>, int> memo;

int dp(int left, int x, int y, int last){
    if(!left) return 1;
    if(last*left>x*a+y*b) return 0;
    if(memo.count({left, x, y, last})) return memo[{left, x, y, last}];
    int &ans = memo[{left, x, y, last}];
    ans = 0;
    fo(i, x+1){
        int val = max(0, (int)ceil((last-i*a)/((double)b)));
        if(val<=y) ans = max(ans, dp(left-1, x-i, y-val, i*a+val*b));
        if(i*a>=last || ans) break;
    }
    return ans;
}

int main() {
    // cout << fixed << setprecision(20);
    // auto start = std::chrono::steady_clock::now(); // since(start).count()
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit); // remove if to endof file

    int n, x, y;
    cin >> x >> a >> y >> b >> n;
    if(x>y){
        swap(x, y);
        swap(a, b);
    }
    int ans = 0;
    fo(i, x+1){
        fo(j, y+1){
            if(dp(n-1, x-i, y-j, i*a+j*b))ans = max(ans, i*a+j*b);
        }
    }
    cout << ans << "\n";
    

    return 0;
}