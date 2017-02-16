#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
typedef pair<int, int> pii;
typedef vector<int> vi;

struct UF {
	vi v;
	UF(int n) : v(n, -1) {}
	int find(int x) { return v[x] < 0 ? x : v[x] = find(v[x]); }
	void join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (-v[a] < -v[b]) swap(a, b);
		v[a] += v[b];
		v[b] = a;
	}
};

// Minimum spanning arborescence, derived from https://github.com/atofigh/edmonds-alg/.

struct EdgeNode {
	int source, target, weight, oweight;
	EdgeNode* parent = nullptr;
	bool removed = false;
	vector<EdgeNode*> children;
	bool beats(const EdgeNode& other) const { return weight < other.weight; }

	tuple<int, int, int> output() const { return make_tuple(source, target, oweight); }
	EdgeNode(int s, int t, int w) : source(s), target(t), weight(w), oweight(w) {}
};

vector<tuple<int, int, int>> minArborescence(const vector<vector<pii>>& ed, int the_root) {
	vector<EdgeNode> all_edges;
	int N = (int)ed.size();

	rep(i,0,N) trav(e, ed[i]) {
		if (e.first != i)
			all_edges.emplace_back(i, e.first, e.second);
	}

	vector<vector<EdgeNode*>> in_edges(N);
	trav(en, all_edges)
		in_edges[en.target].push_back(&en);

	// Sort and prune in-edges (not really needed in our case)
	vector<EdgeNode*> bestIn(N);
	trav(edge_vec, in_edges) {
		trav(e, edge_vec) {
			EdgeNode*& f = bestIn[e->source];
			if (!f || e->beats(*f)) f = e;
		}
		edge_vec.clear();
		rep(i,0,N) if (bestIn[i]) {
			edge_vec.push_back(bestIn[i]);
			bestIn[i] = nullptr;
		}
	}

	vi edge_weight_change(N);
	vi roots, final_roots, min(N);
	vector<vector<EdgeNode*>> cycle(N);
	UF S(2*N), W(2*N);
	vector<EdgeNode*> lambda(N), enter(N), F;

	final_roots.push_back(the_root);
	rep(v,0,N) {
		min[v] = v;
		if (v != the_root)
			roots.push_back(v);
	}

	while (!roots.empty()) {
		int cur = roots.back();
		roots.pop_back();

		assert(!in_edges[cur].empty());
		// (or add min[cur] to final_roots and continue if this happens)

		// Find an optimum-weight edge entering cur
		EdgeNode* crit = in_edges[cur].front();
		trav(en, in_edges[cur]) {
			if (en->beats(*crit))
				crit = en;
		}

		// Insert crit into "F" and let any edges in
		// cycle[cur] be its children.
		F.push_back(crit);
		trav(en, cycle[cur]) {
			en->parent = crit;
			crit->children.push_back(en);
		}

		// If crit is a leaf in "F", then add a
		// pointer to it.
		if (cycle[cur].empty())
			lambda[cur] = crit;

		// If adding crit didn't create a cycle
		if (W.find(crit->source) != W.find(crit->target))
		{
			enter[cur] = crit;
			W.join(crit->source, crit->target);
		}
		else // If adding crit did create a cycle
		{
			// Find the edges of the cycle, the
			// representatives of the strong components in the
			// cycle, and the least costly edge of the cycle.
			vector<EdgeNode*> cycle_edges;
			vi cycle_repr;
			EdgeNode* worst_edge = crit;
			enter[cur] = 0;

			cycle_edges.push_back(crit);
			cycle_repr.push_back(S.find(crit->target));
			for (int v = S.find(crit->source);
				enter[v] != 0;
				v = S.find(enter[v]->source))
			{
				cycle_edges.push_back(enter[v]);
				cycle_repr.push_back(v);
				if (worst_edge->beats(*enter[v]))
					worst_edge = enter[v];
			}

			// change the weight of the edges entering
			// vertices of the cycle.
			trav(en, cycle_edges) {
				edge_weight_change[S.find(en->target)] =
					worst_edge->weight - en->weight;
			}
			trav(v, cycle_repr) {
				trav(en, in_edges[v])
					en->weight += edge_weight_change[v];
			}

			// Save the vertex that would be root if the newly
			// created strong component would be a root.
			int cycle_root = min[S.find(worst_edge->target)];

			// Union all components of the cycle into one component.
			int new_repr = cycle_repr.front();
			trav(v, cycle_repr)
				S.join(v, new_repr);
			new_repr = S.find(new_repr);
			min[new_repr] = cycle_root;
			roots.push_back(new_repr);
			cycle[new_repr] = move(cycle_edges);

			// Merge all in_edges of the cycle into one list.
			trav(v, cycle_repr) {
				trav(e, in_edges[v]) {
					if (S.find(e->source) == new_repr) continue;
					EdgeNode*& f = bestIn[e->source];
					if (!f || e->beats(*f)) f = e;
				}
			}
			vector<EdgeNode*> new_in_edges;
			rep(i,0,N) if (bestIn[i]) {
				new_in_edges.push_back(bestIn[i]);
				bestIn[i] = nullptr;
			}
			in_edges[new_repr] = move(new_in_edges);
			edge_weight_change[new_repr] = 0;
		}
	}

	// Extract the optimum branching
	vector<EdgeNode*> eroots;
	trav(en, F) if (!en->parent) eroots.push_back(en);

	auto remove = [&](EdgeNode* en) {
		while (en) {
			en->removed = true;
			trav(child, en->children) {
				eroots.push_back(child);
				child->parent = 0;
			}

			en->children.clear();
			en = en->parent;
		}
	};

	assert(!lambda[the_root]);
	if (lambda[the_root]) remove(lambda[the_root]);

	vector<tuple<int, int, int>> output;
	while (!eroots.empty()) {
		EdgeNode* en = eroots.back(); eroots.pop_back();
		if (en->removed) continue;
		output.push_back(en->output());
		remove(lambda[en->target]);
	}
	return output;
}

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int N;
	cin >> N;
	vi cost(N);
	rep(i,0,N) cin >> cost[i];
	vector<vi> mat(N, vi(N));
	rep(i,0,N) rep(j,0,N) cin >> mat[i][j];

	vector<vector<pii>> ed(N+1);
	rep(i,0,N) rep(j,0,N) {
		ed[i].emplace_back(j, mat[i][j]);
	}
	rep(i,0,N) ed[N].emplace_back(i, cost[i]);

	auto res = minArborescence(ed, N);
	int sum = 0;
	trav(ed, res) {
		// cout << get<0>(ed) << ' ' << get<1>(ed) << endl;
		sum += get<2>(ed);
	}
	cout << sum << endl;
	exit(0);
}
