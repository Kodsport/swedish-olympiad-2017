#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a = (b); a < (c); a++)
#define iter(it, c) for(auto it = c.begin(); it != c.end(); ++it)

typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef pair<int, int> pii;


struct UF {
	int N;
	vi p;
	UF(){};
	UF(int N){
		this->N = N;
		p.resize(N);
		rep(i, 0, N)
			p[i] = i;
	};
	int par(int a){
		if (p[a] == a)
			return a;
		return p[a] = par(p[a]);
	}
	void join(int a, int b){ // put b in a
		//par(a), par(b);
		p[b] = a;
	}
};


int n, m;
int curheight;
UF uf;

struct node {
	int height, ans = 0;
	vector<int> adj;
	node(){}
};

struct region {
	int highest = 0;
	vi remaining; //height, id
	region(){}
};

vector<region> regions;
vector<node> nodes;

const bool debug = 0;

void merge(int a, int b) {
	int pa = uf.par(a), pb = uf.par(b);
	if (pa == pb)
		return;

	if (nodes[regions[pa].remaining[0]].height < nodes[regions[pb].remaining[0]].height)
		swap(pa, pb);
	if (nodes[regions[pa].remaining[0]].height != nodes[regions[pb].remaining[0]].height){
		for (int nd : regions[pb].remaining)
			nodes[nd].ans = nodes[nd].height-curheight;
	} else for (int nd : regions[pb].remaining){
		regions[pa].remaining.push_back(nd);
	}

	uf.p[pb] = pa;
}

bool comp(int i , int j){
	return nodes[i].height > nodes[j].height;
}

int main(){
	cin >> n >> m;
	regions.resize(n);
	nodes.resize(n);
	uf = UF(n);

	rep(i, 0, n){
		cin >> nodes[i].height;
		regions[i].highest = nodes[i].ans = nodes[i].height;
		regions[i].remaining.push_back(i);
	}

	rep(i, 0, m){
		int a, b;
		cin >> a >> b;
		a --, b--;
		nodes[a].adj.push_back(b);
		nodes[b].adj.push_back(a);
	}

	priority_queue<pii> q;
	rep(i, 0, n)
		q.push(pii(nodes[i].height, i));

	vi qq;
	rep(i, 0, n)
		qq.push_back(i);
	sort(qq.begin(), qq.end(), comp);

	vi vis(n, 0);
	/*
	while(!q.empty()){
		pii cur = q.top();
		q.pop();
		curheight = cur.first;
		int here = cur.second;

		for(int nxt : nodes[here].adj)
			if (vis[nxt])
				merge(here, nxt);
		vis[here] = 1;
	}
	*/
	for(int here : qq){
		curheight = nodes[here].height;
		for(int nxt : nodes[here].adj)
			if (vis[nxt])
				merge(here, nxt);
		vis[here] = 1;
	}

	rep(i, 0, n)
		cout << nodes[i].ans << " ";
}
