// usage: ./a.out input_file correct_output output_dir < contestants_output

#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(it, v) for(auto& it : v)
#define sz(x) (int)(x).size()
typedef vector<int> vi;
typedef pair<int, int> pii;

#include "LinkCutTree.h"

string input_file, output_dir, answer_file;

void die(const string& msg) {
	cout << msg << endl;
    exit(43);
}

void accept() {
    exit(42);
}

void assert_done(istream& is) {
	try {
		string dummy;
		is >> dummy;
		die("extraneous data: " + dummy);
	} catch(...) {}
}

int main(int argc, char** argv) {
	if (argc < 4) exit(1);
	cin.sync_with_stdio(0);
	cin.tie(0);

	input_file = argv[1];
	answer_file = argv[2];
	output_dir = argv[3];

	int N;
	set<pair<int, int>> curEdges;
	set<pair<int, int>> targetEdges;
	ifstream fin(input_file);
	fin.exceptions(cin.failbit | cin.badbit | cin.eofbit);
	fin >> N;
	rep(i,0,N-1) {
		int a, b;
		fin >> a >> b;
		if (a > b) swap(a, b);
		curEdges.emplace(a, b);
	}
	rep(i,0,N-1) {
		int a, b;
		fin >> a >> b;
		if (a > b) swap(a, b);
		targetEdges.emplace(a, b);
	}
	assert_done(fin);
	fin.close();

	int bestM;
	fin.open(answer_file);
	fin >> bestM;
	fin.close();

	try {
	cin.exceptions(cin.failbit | cin.badbit | cin.eofbit);

	int M;
	cin >> M;
	if (M != bestM) die("Uses more moves than judge");

	LinkCut lc(N);
	trav(it, curEdges) lc.link(it.first, it.second);
	rep(i,0,M) {
		int a, b, a2, b2;
		cin >> a >> b >> a2 >> b2;
		if (a > b) swap(a, b);
		if (a2 > b2) swap(a2, b2);
		if (!curEdges.count(pii(a, b))) die("Erasing invalid edge");
		curEdges.erase(pii(a, b));
		if (!targetEdges.count(pii(a2, b2))) die("Inserting edge not part of new system");
		curEdges.insert(pii(a2, b2));
		lc.cut(a, b);
		if (lc.connected(a2, b2)) die("Move disconnected the tree!");
		lc.link(a2, b2);
		assert(lc.connected(a, b));
	}
	if (curEdges != targetEdges) {
		die("New system does not match the plan");
	}
	accept();
	} catch(...) {
		die("IO failure");
	}
}
