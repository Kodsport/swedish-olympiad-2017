// usage: ./a.out input_file correct_output output_dir < contestants_output
#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define trav(a, x) for(auto& a : x)
#define min(a, b) a<b ? a : b
typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> pii;

static string input_file, output_dir, answer_file;

void wrong_answer(const string& msg) {
    cout << msg << endl;
    ofstream(output_dir + "/score.txt") << 0;
    exit(43);
}

void accept(long double score) {
    ofstream(output_dir + "/score.txt") << setprecision(2) << fixed << score;
    exit(42);
}

void judge_error(const string& msg) {
	cout << msg << endl;
	exit(1);
}

template <class F>
void assert_done(istream& is, F fail) {
    try {
        string dummy;
        is >> dummy;
		if (is) fail("extraneous data: " + dummy);
    } catch(...) {}
}

struct inp {
	int T, N, W;
	map<int, int> blocks;
};

bool no_gap_above(const set<pair<int, bool>>& below, int point) {
	if (below.count({point, true}) && below.count({point, false})) return true;
	if (below.count({point, true}) || below.count({point, false})) {
		return false;
	}
	return (*below.lower_bound({point, false})).second == false;
}

bool no_gaps_above(const set<pair<int, bool>>& below, const set<pair<int, bool>>& above) {
	trav(it, above) {
		if (!no_gap_above(below, it.first)) return false;
	}
	return true;
}

bool no_holes_above(const vector<pii>& below, const vector<pii>& above) {
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

template <class F>
int height(istream& is, inp &data, F fail) {
	int H;
	is >> H;
	if (H < 0) fail("Negative height\n");

	map<int, int> blocks = data.blocks;

	set<pair<int, bool>> row;
	vector<pii> row2;

	row2.push_back({0, data.W});
	row.insert({0, true});
	row.insert({data.W, false});

	rep(i, 0, H) {
		int B;
		if (!(is >> B))
			fail("Could not read answer.\n");

		if (B <= 0) fail("Can not have a non positive amount of blocks\n");
		set<pair<int, bool>> nrow;
		vector<pii> nrow2;

		int lastPos = 0;
		rep(j,0,B) {
			int P, L;
			if (!(is >> P >> L))
				fail("Could not read answer.\n");
			
			if (P < 0 || P >= data.W)
				fail("Invalid left position of block\n");
			if (blocks[L]-- == 0) 
				fail("Try to use block we dont have\n");

			int R = P + L;
			if (R <= 0 || P + L > data.W) 
				fail("Invalid right position of block\n");
			if (P < lastPos) 
				fail("New block is not to the right!\n");
			lastPos = R;

			nrow.insert({P, true});
			nrow.insert({R, false});
			if (!nrow2.empty() && nrow2.back().second == P)
				nrow2.back().second = R;
			else
				nrow2.push_back({P, R});
		}
		if (lastPos != data.W) {
			fail("Did not cover row edges\n");
		}

		// Add infinite fake blocks to left and right
		row.insert({0, false});
		row.insert({data.W, true});
		if (!no_gaps_above(row, nrow)) 
			fail("Gap over hole\n");
		if (!no_holes_above(row2, nrow2)) 
			fail("Hole over hole\n");
		row = nrow;
		row2 = nrow2;
	}
	assert_done(is, fail);
	return H;
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

	// read in input_file
	inp data;

	fin >> data.T >> data.N >> data.W;
	rep(i, 0, data.N) {
		int x;
		fin >> x;
		data.blocks[x]++;
	}

	assert_done(fin, wrong_answer);
	fin.close();

	ifstream fans(answer_file);

    try {
		cin.exceptions(cin.failbit | cin.badbit | cin.eofbit);
		long double h = height(cin, data, wrong_answer);
		long double besth = height(fans, data, judge_error);

		long double ratio = h / besth;
		if (data.T == 0) accept(0);
		else accept(10.0 * ratio);
    } catch(...) {
        wrong_answer("IO failure");
    }
}