#pragma GCC target("popcnt")
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

ll best(string& chairs, ll index, ll state, ll satisfied, bool firstLeftTaken)
{
    if (index == chairs.size()) {
        ll ret = popcount((unsigned long long)satisfied);
        if (satisfied & (index-1))
        {
            bool active = state & (1 << ((index - 1) % (chairs.size() + 1)));
            switch (chairs[index - 1])
            {
            
            case 'H':
                if (active && firstLeftTaken)
                {
                    ret--;
                }
                break;
            case 'B':
                if (active && firstLeftTaken)
                {
                    ret--;
                }
                break;
            }
        }

        return ret;
    }
    ll ret = -1;

    bool active = state & (1<<((index - 1) % (chairs.size()+1)));
    switch (chairs[index])
    {
    case 'A':
        if (active)
        {
            ret = max(ret, best(chairs, index + 1, state | (1 << index), satisfied | (1 << index), firstLeftTaken));
            ret = max(ret, best(chairs, index + 1, state, satisfied, firstLeftTaken));
        }
        else
        {
            ret = max(ret, best(chairs, index + 1, state, satisfied | (1 << index), (index == 0) ? true : firstLeftTaken));
        }
        break;
    case 'H':
        ret = max(ret, best(chairs, index + 1, state | (1 << index), satisfied | (1 << index), firstLeftTaken));
        ret = max(ret, best(chairs, index + 1, state, satisfied, firstLeftTaken));
        break;
    case 'V':
        if (active)
        {
            ret = max(ret, best(chairs, index + 1, state, satisfied, firstLeftTaken));
        }
        else
        {
            ret = max(ret, best(chairs, index + 1, state, satisfied | (1 << index), (index == 0) ? true : firstLeftTaken));
        }
        break;
    case 'B':
        if (active)
        {
            ret = max(ret, best(chairs, index + 1, state, satisfied, firstLeftTaken));
        }
        else
        {
            ret = max(ret, best(chairs, index + 1, state | (1 << index), satisfied | (1 << index), (index == 0) ? true : firstLeftTaken));
            ret = max(ret, best(chairs, index + 1, state, satisfied, firstLeftTaken));
        }
        break;
    case 'I':
        ret = max(ret, best(chairs, index + 1, state, satisfied | (1 << index), firstLeftTaken));
    default:
        break;
    }

    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);


    ll _;
    cin >> _;
    string chairs;
    cin >> chairs;

    ll ans = -1;
    ans = max(ans, best(chairs, 0, 0, 0, false));
    cout << ans << "\n";

    return 0;
}
