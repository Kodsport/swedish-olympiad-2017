#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vi;

vector<vi> compress(const vector<vi>& G, int L) {
	vector<vi> ret(sz(G));
	rep(i,0,sz(G)) {
		multiset<int> s;
		rep(j,0,L-1) s.insert(G[i][j].first);
		rep(j,0,L-1) s.insert(G[i][j].second);
		rep(j,0,sz(G[i])-L+1){
			s.insert(G[i][L-1+j].first);
			s.insert(G[i][L-1+j].second);
			int hi = *s.rbegin();
			int lo = *s.begin();
			ret[i].push_back(make_pair(lo, hi));
			s.erase(s.find(G[i][j].first));
			s.erase(s.find(G[i][j].second));
		}
	}
	return ret;
}

vector<vi> transpose(const vector<vi> G) {
	vector<vi> ret(sz(G[0]), vi(sz(G)));
	rep(i,0,sz(G)) rep(j,0,sz(G[0])) ret[j][i] = G[i][j];
	return ret;
}

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int R, C, L;
	cin >> R >> C >> L;
	vector<vi> grid(R, vi(C));
	rep(i,0,R) rep(j,0,C) cin >> grid[i][j].first;
	rep(i,0,R) rep(j,0,C) grid[i][j].second = grid[i][j].first;
	grid = compress(grid, L);
	grid = transpose(grid);
	grid = compress(grid, L);
	grid = transpose(grid);
	pair<int, pair<int, int>> best(1000000001, make_pair(0, 0));
	rep(i,0,sz(grid)) rep(j,0,sz(grid)) {
		if (grid[i][j].first != -1) {
			best = min(best, make_pair(grid[i][j].second - grid[i][j].first, make_pair(i, j)));
		}
	}
	cout << best.second.first << " " << best.second.second << endl;
}
