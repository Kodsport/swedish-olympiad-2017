// usage: ./a.out input_file correct_output output_dir < contestants_output

#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define sz(x) (int)(x).size()
typedef vector<int> vi;
typedef pair<int, int> pii;

string input_file, output_dir, answer_file;

void die(const string& msg) {
	cout << msg << endl;
	ofstream(output_dir + "/score.txt") << 0;
    exit(43);
}

void accept(double score) {
	ofstream(output_dir + "/score.txt") << setprecision(2) << fixed << score;
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

	ifstream fin(input_file);
	fin.exceptions(cin.failbit | cin.badbit | cin.eofbit);
	string s;
	fin >> s;
	assert_done(fin);
	fin.close();

	int S = sz(s);
	int maxn = 2*S;

	int bestn;
	fin.open(answer_file);
	fin >> bestn;
	fin.close();

	try {
	cin.exceptions(cin.failbit | cin.badbit | cin.eofbit);

	int N, startnode, endnode;
	cin >> N >> startnode >> endnode;
	if (N <= 1 || N >= maxn) die("invalid size");
	if (startnode < 0 || endnode < 0 || startnode >= N || endnode >= N || startnode == endnode)
		die("invalid start/end nodes");

	vector<array<int, 3>> ed(N);
	rep(i,0,N) rep(j,0,3) {
		cin >> ed[i][j];
		if (ed[i][j] < 0 || ed[i][j] >= N) die("edge out of range");
		if (ed[i][j] == i) die("self-edge");
	}
	assert_done(cin);

	rep(i,0,N) rep(j,0,3) {
		if (ed[ed[i][j]][j] != i) die("graph must be undirected");
	}

	vi seen(N);
	vi stack = {0};
	while (!stack.empty()) {
		int ind = stack.back();
		stack.pop_back();
		if (seen[ind]++) continue;
		rep(j,0,3) stack.push_back(ed[ind][j]);
	}
	rep(i,0,N) if (!seen[i]) die("graph must be connected");

	set<pii> seen2;
	int at = startnode, sat = 0;
	while (true) {
		if (at == endnode) die("end node must not be reachable");
		if (!seen2.insert(pii(at, sat)).second) break;
		char c = s[sat++];
		if (c == 'R') at = ed[at][0];
		else if (c == 'G') at = ed[at][1];
		else if (c == 'B') at = ed[at][2];
		else assert(0);
		if (sat == S) sat = 0;
	}

	double rat1 = max(N / (double)bestn, 1.0);
	double rat2 = maxn / (double)bestn;
	//assert(rat2 > 1 && rat1 < rat2);
	double rat = log(rat1) / log(rat2);
	double score = 10 * (1 - rat);
	if (s=="RGB") accept(0);
	accept(min(10.0,score));
	} catch(...) {
		die("IO failure");
	}
}
