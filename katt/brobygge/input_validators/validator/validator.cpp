#include "validator.h"

struct UF {
	vector<int> v;
	UF(int n) : v(n, -1) {}
	int find(int x) { return v[x] < 0 ? x : v[x] = find(v[x]); }
	bool join(int a, int b) {
		a = find(a);
		b = find(b);
		if (a == b) return false;
		if (-v[a] < -v[b]) swap(a, b);
		v[a] += v[b];
		v[b] = a;
		return true;
	}
};


void run() {
	int n = Int(2, int(1e5));
	Endl();
	
	UF uf(n);
	set<pair<int,int>> seen;
	for (int i = 0; i < n-1; i++)
	{
		int a = Int(0, n-1);
		Space();
		int b = Int(0, n-1);
		Space();
		Int(0,1000);
		Endl();
		assert(uf.join(a,b));
		if (a>b) swap(a,b);
		assert(a!=b);
		seen.insert(make_pair(a,b));
	}
	
	int e = Int(0, 2);
	Endl();
	int e_is = (int)Arg("e", -1);
	if (e_is != -1) assert(e==e_is);
	for (int i = 0; i < e; i++)
	{
		int a = Int(0, n-1);
		Space();
		int b = Int(0, n-1);
		Space();
		Int(0,1000);
		Endl();
		if (a>b) swap(a,b);
		assert(a!=b);
		assert(seen.find(make_pair(a,b))==seen.end());
		seen.insert(make_pair(a,b));
	}

	int q = Int(0, int(1e5));
	Endl();
	for (int i = 0; i < q; i++)
	{
		Int(0,n-1);
		Space();
		Int(0,n-1);
		Endl();
	}
	Eof();
}
