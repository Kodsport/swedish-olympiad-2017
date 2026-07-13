#include<bits/stdc++.h>
#include<unordered_set>

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define PI 3.141592653
#define rep(i,a,b) for(int i = a; i<int(b);++i)
#define rrep(i,a,b) for(int i = a; i>int(b);--i)
#define all(v) v.begin(),v.end()
#define trav(a, x) for(auto& a : x)

typedef long long ll;


const long long inf = 1e15;

using namespace std;

void printint(vector < ll > vec)
{
    for (auto a : vec) {
        cout << a << " ";
    }
    cout << endl;
}
void printstr(vector < string > vec)
{
    for (auto a : vec) {
        cout << a << endl;
    }
}
void printchar(vector < char > vec)
{
    for (auto a : vec) {
        cout << a;
    }
    cout << endl;
}
void print2d(vector < vector < ll >> vec)
{
    for (int i = 0; i < vec.size(); i++) {
        printint(vec[i]);
    }
    cout << endl;
}
void printmap(map<int, long double> myMap) {
    for (auto it = myMap.cbegin(); it != myMap.cend(); ++it)
    {
        std::cout << it->first << " ";
        cout << it->second << " ";
    }
}
void print2dchar(vector < vector < char >> vec)
{
    for (auto a : vec) {
        printchar(a);
    }
    cout << endl;
}
bool sortcol(const vector<int>& v1,
    const vector<int>& v2) {
    return v1[1] < v2[1];
}
void printsetint(set<ll> s) {
    for (auto it = s.begin(); it != s.end(); ++it) {
        cout << *it;
    }
}
void printsetpairint(set<pair<int, int>> s) {
    for (auto it = s.begin(); it != s.end(); ++it) {
        pair<int, int> cur = *it;
        cout << cur.first << " " << cur.second;
    }
    cout << endl;
}
void printsetstring(set<string> s) {
    for (auto it = s.begin(); it != s.end(); ++it) {
        cout << *it << endl;
    }
}
struct MaxTree {
    typedef int T;
    static constexpr T unit = INT_MIN;
    T f(T a, T b) { return max(a, b); } // (any associative fn)
    vector<T> s; int n;
    MaxTree(int n = 0, T def = unit) : s(2 * n, def), n(n) {}
    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(int b, int e) { // query [b, e)
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};
struct MinTree {
    typedef int T;
    static constexpr T unit = INT_MAX;
    T f(T a, T b) { return min(a, b); } // (any associative fn)
    vector<T> s; int n;
    MinTree(int n = 0, T def = unit) : s(2 * n, def), n(n) {}
    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(int b, int e) { // query [b, e)
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};
int main()
{
    cin.sync_with_stdio(false);
    ll x, a, y, b, n;

    cin >> x >> a >> y >> b >> n;
    bitset<2000001> dp;
    dp[0] = 1;
    set<ll> s;
    vector<ll> v;
    vector<bool> visited(2e6 + 1);
    rep(i, 0, y) {
        dp |= dp << b;
    }
    rep(i, 0, dp.size()) {
        visited[i] = dp[i];
    }
    rep(i, 0, x) {
        dp |= dp << a;
    }
    rep(i, 0, dp.size()) {
        if (dp[i])v.push_back(i);
    }
    ll ans =0;
    rep(o,0,x+1){
        ll l = 0, r=y;
        while (l <= r) {
            ll mid = l + (r - l) / 2;
            ll cur = o*a+b*mid;
            ll taken = cur;
            bool done = true;
            ll curx = x-o, cury = y-mid;
            rep(i, 1, n) {
                auto it = lower_bound(all(v), taken + cur);
                bool found = false;
                while (it != v.end()) {
                    rep(i, 0, curx + 1) {
                        ll res = a * i;
                        if (*it - taken - res < 0 || *it - taken - res >= visited.size())continue;
                        if (visited[*it - taken - res] && (*it - taken - res) / b <= cury) {
                            curx -= i;
                            cury -= (*it - taken - res) / b;
                            found = true;
                            break;
                        }
                    }
                    if (found)break;
                    it++;
                }
                if (it == v.end()) {
                    done = false;
                    break;
                }
                cur = *it - taken;
                taken = *it;

            }
            if (done) {
                l = mid + 1;
                ans = max(ans,o*a+mid*b);
            }
            else r = mid - 1;
        }
    }
    cout << ans;
    return 0;
}
