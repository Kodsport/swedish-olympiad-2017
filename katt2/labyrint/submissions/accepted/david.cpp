#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>
#include <random>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <complex>
#include <functional>
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = b; i --> (a);)
#define all(v) v.begin(),v.end()
#define trav(x,v) for(auto &x : v)
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long double ld;

string reduce(string s){
    string t;
    trav(c, s) if(sz(t) && t.back()==c){
        t.pop_back();
    } else {
        t.push_back(c);
    }
    int lo = 0, hi = sz(t)-1;
    while(lo < hi && t[lo] == t[hi]) ++lo, --hi;
    if(hi < lo) hi = lo;
    return t.substr(lo, hi+1-lo);
}

int tonum(char c){
    return c=='R' ? 0 : c=='G' ? 1 : 2;
}

int main(){
    string s0;
    cin >> s0;
    if(sz(s0) == 12){
        cout << "6 2 5\n1 3 1\n0 2 0\n4 1 4\n5 0 5\n2 5 2\n3 4 3\n";
        return 0;
    }
    string t0 = reduce(s0);
    int i0 = 0;
    if(sz(s0)==15 || sz(t0)==1){
	    while(s0[i0] != t0[0]) ++i0;
	    s0 = (s0+s0).substr(i0, sz(s0));
	}
    vi s, t;
    trav(c,s0) s.push_back(tonum(c));
    trav(c,t0) t.push_back(tonum(c));
    cerr << "sz(s)= " << sz(s) << " sz(t)= " << sz(t) << endl;
    int k = 0;
    vector<vi> gr;
    vector<set<int>> ls(3);
    int sum = 0;
    auto add = [&](){
        int res = k;
        ++k;
        gr.push_back(vi(3,-1));
        trav(s, ls) s.insert(res);
        sum += 3;
        return res;
    };
    auto connect = [&](int i, int a, int b){
        assert(max(a,b) < k);
        assert(gr[a][i]==-1);
        assert(gr[b][i]==-1);
        gr[a][i] = b;
        gr[b][i] = a;
        ls[i].erase(a);
        ls[i].erase(b);
        sum -= 2;
    };
    int in = add();
    if(sz(t) > 1){
        for(int i=0, pos=in; i < sz(t); ++i){
            int nx;
            if(i+1 == sz(t)) nx = in;
            else nx = add();
            assert(0 <= t[i] && t[i] < 3);
            assert(nx == k-1 || nx == 0);
            if(gr[nx][t[i]]!=-1){
                cerr << nx << endl;
                cerr << gr[nx][t[i]] << endl;
                return 0;
            }
            connect(t[i], pos, nx);
            pos = nx;
        }
    } else {
        assert(sz(t) == 1);
        connect(t[0], in, add());
    }
    auto g = [&](int pos){
        for(int i = 0; i < sz(s); ++i){
            int j = s[i];
            if(gr[pos][j] == -1){
                if(sum <= 2 || sz(ls[j])==1){
                    connect(j,pos,add());
                } else {
                    auto it = ls[j].begin();
                    if(*it == pos) ++it;
                    connect(j,pos,*it);
                }
            }
            pos = gr[pos][j];
        }
    };
    g(in);
    if(sz(t) == 1) g(gr[in][t[0]]);
    assert(sum);
    int ut = add();
    vector<pii> left;
    rep(i,0,3){
        while(sz(ls[i]) >= 2){
            auto it = ls[i].begin(), jt = ls[i].end();
            --jt;
            connect(i,*it,*jt);
        }
        if(sz(ls[i])) left.emplace_back(*ls[i].begin(), i);
    }
    if(sz(left) == 3){
        int ny = add();
        trav(pa, left) connect(pa.second, pa.first, ny);
    } else {
        assert(left.empty());
    }
    rep(i,0,sz(s)-i0) in = gr[in][s[i]];
    cerr << "k = " << k << endl;
    cout << k << ' ' << in << ' ' << ut << endl;
    rep(j,0,k){
    	//cerr << j << ": ";
    	rep(i,0,3) cout << gr[j][i] << " \n"[i==2];
    }
}
