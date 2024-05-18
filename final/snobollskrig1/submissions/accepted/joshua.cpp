#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define enablell 1

#define ll long long
#if enablell
#define int ll
#endif
#define vi vector<int>
#define vb vector<bool>
#define vvb vector<vb>
#define vvvb vector<vvb>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vvvvi vector<vvvi>
#define p2 pair<int, int>
#define p3 tuple<int,int,int>
#define p4 tuple<int,int,int,int>
#define vp2 vector<p2>
#define vvp2 vector<vp2>
#define vp3 vector<p3>
#define vp4 vector<p4>
#if enablell
#define inf 1e18
#else
#define inf int(1e9)
#endif

#define read(a) cin >> a
#define read2(a,b) cin >> a >> b
#define write(a) cout << (a) << "\n"
#define quit cout << endl; _Exit(0);
#define dread(type, a) type a; cin >> a
#define dread2(type, a, b) dread(type, a); dread(type, b)
#define dread3(type, a, b, c) dread2(type, a, b); dread(type, c)
#define dread4(type, a, b, c, d) dread3(type, a, b, c); dread(type, d)
#define dread5(type, a, b, c, d, e) dread4(type, a, b, c, d); dread(type, e)
#ifdef _DEBUG
#define noop cout << "";
#define deb __debugbreak();
#else
#define noop ;
#define deb ;
#endif

#define rep(i, high) for (int i = 0; i < high; i++)
#define repp(i, low, high) for (int i = low; i < high; i++)
#define repe(i, container) for (auto& i : container)
#define per(i, high) for (int i = high; i >= 0; i--)
#define perr(i, low, high) for (int i = high; i >= low; i--)

#define readpush(type,vect) type temp; read(temp); vect.(temp);
#define readvector(type, name, size) vector<type> name(size); rep(i,size) {dread(type,temp); name[i]=temp;}
#define readinsert(type,a) {type temp; read(temp); a.insert(temp);}
#define all(a) begin(a),end(a)
#define setcontains(set, x) (set.find(x) != set.end())
#define stringcontains(str, x) (str.find(x) != string::npos)
#define within(a, b, c, d) (a >= 0 && a < b && c >= 0 && c < d)
#define insideinterval(v, interval) (v >= interval.first && v <= interval.second)
#define sz(container) ((int)container.size())
#define mp(a,b) (make_pair(a,b))
#define first(a) (*begin(a))

#define ceildiv(x,y) ((x + y - 1) / y)
#define fract(a) (a-floor(a))
#define sign(a) ((a>0) ? 1 : -1)

auto Start = chrono::high_resolution_clock::now();

inline void fast()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

template <typename T, typename U>
void operator+=(std::pair<T, U>& l, const std::pair<T, U>& r)
{
    l = { l.first + r.first,l.second + r.second };
}

#define UNVISITED 0
#define OCCUPIED 1
#define FIGHTING 2

struct node
{
    int state;
    set<int> countries;
    vp2 edges;
};

struct edge
{
    int weight;
    int a;
    int b;
    bool operator<(const edge& rhs) const
    {
        return weight > rhs.weight;
    }
    edge(int weight, int a, int b) : weight(weight), a(a), b(b) {}
};


int32_t main()
{
    fast();

#if 0
    ifstream cin("C:\\Users\\Matis\\source\\repos\\Comp prog\\x64\\Debug\\in.txt");
#endif

    dread3(int, n, l, m);

    vector<node> nodes(n);

    rep(i, l)
    {
        dread(int, location);
        nodes[location].state = OCCUPIED;
        nodes[location].countries.insert(i);
    }



    priority_queue<edge> countries;
    rep(i, m)
    {
        dread3(int, a, b,weight);
        nodes[a].edges.emplace_back(b, weight);
        nodes[b].edges.emplace_back(a, weight);

        if (nodes[a].state==OCCUPIED)
        {
            countries.emplace(weight, a, b);
        }
        if (nodes[b].state == OCCUPIED)
        {
            countries.emplace(weight, b, a);
        }
    }



    set<p2> fighting;

    int t = 0;
    while (countries.size())
    {
        set<int> affectedNodes;

        while (countries.size() && countries.top().weight == t)
        {
            edge c = countries.top();
            countries.pop();
            int from = c.a;
            int to = c.b;
            //assert(nodes[from].state == OCCUPIED);
            int countryFrom = first(nodes[from].countries);

            if (nodes[to].state == OCCUPIED)
            {
                int mi = min(first(nodes[from].countries), first(nodes[to].countries));
                int ma = max(first(nodes[from].countries), first(nodes[to].countries));
                if (mi == ma) continue;
                fighting.insert(mp(mi,ma));
            }
            else if (nodes[to].state == UNVISITED)
            {
                nodes[to].countries.insert(countryFrom);
                affectedNodes.insert(to);
            }
            else if (nodes[to].state == FIGHTING)
            {
                nodes[to].countries.insert(countryFrom);
            }
        }
        


        repe(n, affectedNodes)
        {
            if (nodes[n].state != UNVISITED)
            {
                deb;
            }
            else
            {
                if (nodes[n].countries.size() == 1)
                {
                    nodes[n].state = OCCUPIED;
                    repe(e, nodes[n].edges)
                    {
                        countries.emplace(t + e.second, n, e.first);
                    }
                }
                else
                {
                    nodes[n].state = FIGHTING;
                }
            }
        }
        if (countries.size()) t = countries.top().weight;
        
    }


    
    repe(n, nodes)
    {
        if (n.state==FIGHTING)
        {
            vi country(all(n.countries));
            rep(i, country.size())
            {
                repp(j, i + 1, country.size())
                {
                    int mi = min(country[i], country[j]);
                    int ma = max(country[i], country[j]);
                    fighting.insert(mp(mi, ma));
                }
            }
        }
    }

    repe(fight, fighting)
    {
        cout << fight.first << " " << fight.second << "\n";
    }

    quit;
}
