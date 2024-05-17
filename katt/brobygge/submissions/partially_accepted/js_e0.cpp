#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define scanf nope
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const pii inf(1 << 29, -1);

template <class T>
struct RMQ {
	vector<vector<T>> jmp;

	RMQ(const vector<T>& V) {
		int N = sz(V), on = 1, depth = 1;
		while (on < sz(V)) on *= 2, depth++;
		jmp.assign(depth, V);
		rep(i,0,depth-1) rep(j,0,N)
			jmp[i+1][j] = min(jmp[i][j],
			jmp[i][min(N - 1, j + (1 << i))]);
	}

	T query(int a, int b) {
		if (b <= a) return inf;
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

typedef vector<pii> vpi;
typedef vector<vpi> graph;

struct LCA {
	vi time;
	vector<int> dist;
	RMQ<pii> rmq;

	LCA(graph& C) : time(sz(C), -99), dist(sz(C)), rmq(dfs(C)) {}

	vpi dfs(graph& C) {
		vector<tuple<int, int, int, int> > q(1);
		vpi ret;
		int T = 0, v, p, d, di;
		while (!q.empty()) {
			tie(v, p, d, di) = q.back();
			q.pop_back();
			if (d) ret.emplace_back(d, p);
			time[v] = T++;
			dist[v] = di;
			trav(e, C[v]) if (e.first != p)
				q.emplace_back(e.first, v, d+1, di + e.second);
		}
		return ret;
	}

	int query(int a, int b) {
		if (a == b) return a;
		a = time[a], b = time[b];
		return rmq.query(min(a, b), max(a, b)).second;
	}
	int distance(int a, int b) {
		int lca = query(a, b);
		return dist[a] + dist[b] - 2 * dist[lca];
	}
};

vi dijkstra(int source, const graph& g) {
	const int inf = 1e9;
	vi dist(sz(g), inf);
	dist[source] = 0;
	set<pii> q;
	q.emplace(0, source);
	while (!q.empty()) {
		int cv, cd;
		tie(cd, cv) = *q.begin();
		q.erase(q.begin());
		trav(it, g[cv]) {
			int nv, ed;
			tie(nv, ed) = it;
			int nd = cd + ed;
			if (nd < dist[nv]) {
				if (dist[nv] != inf) q.erase(pii(dist[nv], nv));
				dist[nv] = nd;
				q.emplace(dist[nv], nv);
			}
		}
	}
	return dist;
}

int main() {
	cin.sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	// Read original graph
	int N;
	cin >> N;
	graph G(N);
	rep(i,0,N-1) {
		int x, y, d;
		cin >> x >> y >> d;
		G[x].emplace_back(y, d);
		G[y].emplace_back(x, d);
	}
	// Root the tree and use LCA to quickly compute pairwise distances
	LCA lca(G);
	// Read extra edges
	set<int> enod;
	int E;
	cin >> E;
	rep(i,0,E) {
		int x, y, d;
		cin >> x >> y >> d;
		enod.insert(x);
		enod.insert(y);
		G[x].emplace_back(y, d);
		G[y].emplace_back(x, d);
	}
	vector<vi> edist;
	trav(it, enod) {
		edist.push_back(dijkstra(it, G));
	}
	int Q;
	cin >> Q;
	rep(i,0,Q) {
		int x, y;
		cin >> x >> y;
		int ans = lca.distance(x, y);
		cout << ans << endl;
	}
}
