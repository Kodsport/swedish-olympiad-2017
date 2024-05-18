#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define sz(x) (int)(x).size()
typedef vector<int> vi;
typedef pair<int, int> pii;

void die(const string& msg) {
	cout << "NO" << endl;
	exit(0);
}

void accept() {
	cout << "YES" << endl;
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
	cin.sync_with_stdio(0);
	cin.tie(0);
	int W, H;
	cin >> W >> H;

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
		row = nrow;
		row2 = nrow2;
	}
	accept();
}
