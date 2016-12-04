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

bool ok2(const set<pair<int, bool>>& below, int point) {
	if (below.count(make_pair(point, true)) && below.count(make_pair(point, false))) return true;
	if (below.count(make_pair(point, true)) || below.count(make_pair(point, false))) {
		return false;
	}
	return (*below.lower_bound(make_pair(point, false))).second == false;
}

bool ok(const set<pair<int, bool>>& below, const set<pair<int, bool>>& above) {
	for (auto& it : above) {
		if (!ok2(below, it.first)) return false;
	}
	return true;
}

bool ok3(const vector<pii>& below, const vector<pii>& above) {
	int prev = -1;
	const int inf = 1 << 29;
	for (auto& it : above) {
		int cur = it.first;
		if (prev != -1) {
			auto it = lower_bound(below.begin(), below.end(), pii(prev, inf));
			auto it2 = lower_bound(below.begin(), below.end(), pii(cur, -1));
			if (it != it2) return false;
			assert(it != below.begin());
			--it;
			if (it->second < cur) return false;
		}
		prev = it.second;
	}
	return true;
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
	int T, N, W;
	fin >> T >> N >> W;
	map<int, int> blocks;
	rep(i,0,N) {
		int x;
		fin >> x; 
		blocks[x]++;
	}
	assert_done(fin);
	fin.close();

	int best;
	fin.open(answer_file);
	fin >> best;
	assert_done(fin);
	fin.close();

	try {
	cin.exceptions(cin.failbit | cin.badbit | cin.eofbit);
	int H;
	cin >> H;
	if (H < 0) die("invalid height");
	set<pair<int, bool>> row;
	vector<pii> row2;
	row2.push_back(pii(0, W));
	row.insert(make_pair(0, true));
	row.insert(make_pair(W, false));
	rep(i,0,H) {
		int B;
		cin >> B;
		if (B <= 0) die("invalid number of blocks");
		set<pair<int, bool>> nrow;
		vector<pii> nrow2;

		int lastPos = 0;
		rep(j,0,B) {
			int P, L;
			cin >> P >> L;
			if (P < 0 || P >= W) die("invalid left position of block");
			if (blocks[L]-- == 0) die("try to use block we dont have");
			int R = P + L;
			if (R <= 0 || P + L > W) die("invalid right position of block");
			if (P < lastPos) die("new block is not to the right!");
			lastPos = R;
			nrow.insert(make_pair(P, true));
			nrow.insert(make_pair(R, false));
			if (!nrow2.empty() && nrow2.back().second == P)
				nrow2.back().second = R;
			else
				nrow2.push_back(pii(P, R));
		}
		if (lastPos != W) {
			die("did not cover row edges");
		}

		// Add infinite fake blocks to left and right
		row.insert(make_pair(0, false));
		row.insert(make_pair(W, true));
		if (!ok(row, nrow)) die("gap over hole");
		if (!ok3(row2, nrow2)) die("hole over hole");
		row = nrow;
		row2 = nrow2;
	}
	assert_done(cin);
	accept(10 * double(H) / double(best));
	} catch(...) {
		die("IO failure");
	}
}
