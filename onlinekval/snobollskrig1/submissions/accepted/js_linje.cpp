#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define sz(x) (int)(x).size()

typedef vector<int> vi;
int main() {
	int N, L, M;
	cin >> N >> L >> M;
	vector<vector<pair<int, int>>> adj(N);
	vector<pair<int, int>> fort;
	rep(i,0,L) {
		int x;
		cin >> x;
		fort.emplace_back(i, x);
	}
	rep(i,0,M){
		int a, b, w;
		cin >> a >> b >> w;
		adj[a].emplace_back(b, w);
		adj[b].emplace_back(a, w);
	}
	int start = -1;
	rep(i,0,N) if(sz(adj[i]) == 1) start = i;
	assert(start != -1);
	vi times(N);
	int t = 0;
	times[start] = ++t;
	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int nx = q.front(); q.pop();
		assert(sz(adj[nx]) <= 2);
		for (auto it : adj[nx]) {
			if (times[it.first]) continue;
			times[it.first] = ++t;
			q.push(it.first);
		}
	}
	sort(fort.begin(), fort.end(), [&](pair<int, int> a, pair<int, int> b) { return times[a.second] < times[b.second]; });
	set<pair<int, int>> ans;
	rep(i,0,L-1) {
		int a = fort[i].first;
		int b = fort[i+1].first;
		ans.emplace(min(a, b), max(a, b));
	}
	for(auto& it : ans) {
		cout << it.first << " " << it.second << endl;
	}
}
