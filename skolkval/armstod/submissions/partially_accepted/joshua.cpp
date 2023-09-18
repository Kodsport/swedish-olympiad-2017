#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define p2 pair<ll, ll>
#define p3 vi
#define p4 vi
#define vp2 vector<p2>
#define vp3 vector<p3>
#define inf 2e9
#define linf 1e17

#define read(a) cin >> a
#define dread(type, a) type a; cin >> a
#define dread2(type, a, b) dread(type, a); dread(type, b)
#define dread3(type, a, b, c) dread(type, a); dread(type, b); dread(type, c)
#define dread4(type, a, b, c, d) dread(type, a); dread(type, b); dread(type, c); dread(type, d)
#define dread5(type, a, b, c, d, e) dread(type, a); dread(type, b); dread(type, c); dread(type, d); dread(type, e)
#define write(a) cout << (a) << endl
#ifdef _DEBUG
#define deb __debugbreak();
#else
#define deb ;
#endif

#define rep(i, high) for (ll i = 0; i < high; i++)
#define repe(i, container) for (auto& i : container)
#define per(i, high) for (ll i = high; i >= 0; i--)

#define readpush(type,vect) type temp; read(temp); vect.push_back(temp);
#define readvector(type, name, size) vector<type> name(size); rep(i,size) {dread(type,temp); name[i]=temp;}
#define readinsert(type,a) {type temp; read(temp); a.insert(temp);}
#define setcontains(set, x) (set.find(x) != set.end())
#define stringcontains(str, x) (str.find(x) != string::npos)
#define all(a) begin(a),end(a)

#define ceildiv(x,y) ((x + y - 1) / y)
#define fract(a) (a-floor(a))

auto Start = chrono::high_resolution_clock::now();

inline void fast()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int best(string& chairs, int index, int state, int satisfied, bool firstLeftTaken)
{
    if (index == chairs.size())
    {
        int ret = __builtin_popcount((unsigned int)satisfied);
        //int ret = _Popcount((unsigned int)satisfied);
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
    int ret = -1;



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

int main()
{
    fast();

#if 0
    //ifstream cin("C:\\Users\\Matis\\source\\repos\\Comp prog\\x64\\Debug\\in.txt");
    ifstream cin("C:\\Users\\Matis\\Downloads\\pixel\\examples\\sample01.in");
#endif

    dread(int, _);
    dread(string, chairs);

    int ans = -1;
    ans = max(ans, best(chairs, 0, 0, 0, false));
    write(ans);

    //return 0;
    _Exit(0);
}