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

template <class T>
void addInterval(set<pair<T, T>>& is, T l, T r) {
	if (l == r) return;
	auto it2 = is.insert({l, r}).first, it = it2++;
	while (it2 != is.end() && it->second >= it2->first) {
		(T&)it->second = max(it->second, it2->second);
		it2 = is.erase(it2);
	}
	while (it != is.begin() && it->first <= (it2 = it, --it2)->second) {
		(T&)it->first = min(it->first, it2->first);
		(T&)it->second = max(it->second, it2->second);
		is.erase(it2);
	}
};

template <class T>
void removeInterval(set<pair<T, T>>& is, T l, T r) {
	if (l == r) return;
	addInterval(is, l, r);
	auto it = --is.lower_bound({l+1, l});
	T r2 = it->second;
	if (it->first == l) is.erase(it);
	else (T&)it->second = l;
	if (r != r2) is.emplace(r, r2);
};

struct Row {

	int W;
	set<pii> blocks;
	set<pii> holes;
	Row(int MX) : W(MX) {
		blocks.insert(pii(0, W));
	}

	void remove(int l, int r) {
		removeInterval(blocks, l, r);
		addInterval(holes, l, r);
	}

	void split(int l, int r, int split) {
		removeInterval(blocks, l, r);
		blocks.insert(pii(l, split));
		blocks.insert(pii(split, r));
	}

	bool splitAt(int sp) {
		auto it = --blocks.upper_bound(pii(sp+1, 0));
		if (it->first <= sp && sp < it->second) {
			split(it->first, it->second, sp);
			return true;
		}
		return false;
	}

	void output() const {
		cout << sz(blocks);
		trav(it, blocks) {
			cout << " " << it.first << " " << (it.second - it.first);
		}
		cout << endl;
	}

	bool isok(int pos) {
		if (pos == 0 || pos == W) return true;
		auto it = --blocks.upper_bound(pii(pos+1, 0));
		if (it->first == pos) return false;
		it = holes.upper_bound(pii(pos+1, 0));
		if (it == holes.begin()) return true;
		--it;
		if (it->first == pos) return false;
		if (it->second == pos) return false;
		return true;
	}

	bool isokhole(int L, int R) {
		auto it = --blocks.upper_bound(pii(L+1, 0));
		return it->first < L && R < it->second;

	}

	
	void dohole(int L, int R) {
		removeInterval(blocks, L, R);
		addInterval(holes, L, R);
	}
};

struct Wall {
	int H, W;
	vector<Row> lines;

	Wall(int H, int W) : H(H), W(W), lines(H, Row(W)) { }

	void output() {
		cout << W << " " << H << endl;
		trav(it, lines) {
			it.output();
		}
	}

	bool randhole(int line, bool conseqcheck) {
		assert(line + 1 != H);
		Row& r = lines[line];
		int pos = rand() % (W + 1);
		auto it = --r.blocks.upper_bound(pii(pos+1, 0));
		int len = it->second - it->first;
		if (len < 3) return false;
		int pre = rand() % (len - 2) + 1;
		int suf = rand() % (len - pre - 1) + 1;

		int L = it->first + pre;
		int R = it->second - suf;
		if (!conseqcheck || (isokhole(line - 1, L, R) && isokhole(line + 1, L, R))) {
			lines[line + 1].dohole(L, R);
			if (!(isokhole(line - 1, L, R) && isokhole(line + 1, L, R))) return true;
		}
		return false;
	}

	bool subhole(int line) {
		assert(line + 1 != H);
		Row& r = lines[line + 1];
		int pos = rand() % (W + 1);
		auto it = r.holes.upper_bound(pii(pos+1, 0));
		if (it == r.holes.begin()) return false;
		--it;
		int len = it->second - it->first;
		if (len < 3) return false;
		int pre = rand() % (len - 2) + 1;
		int suf = rand() % (len - pre - 1) + 1;
		int L = it->first + pre;
		int R = it->second - suf;
		lines[line].dohole(L, R);
		return true;
	}

	bool overlaphole(int line) {
		assert(line + 1 != H);
		Row& r = lines[line];
		int pos = rand() % (W + 1);
		auto it = r.holes.upper_bound(pii(pos+1, 0));
		if (it == r.holes.begin()) return false;
		--it;
		int len = it->second - it->first;
		if (len < 3) return false;
		int pre = rand() % (len - 2) + 1;
		int suf = rand() % (len - pre - 1) + 1;
		int L = it->first + pre - 1;
		int R = it->second - suf - 1;
		lines[line + 1].dohole(L, R);
		return true;
	}


	void randsplit(int line, bool okcheck) {
		Row& r = lines[line];
		int pos = rand() % (W + 1);
		auto it = --r.blocks.upper_bound(pii(pos+1, 0));
		int len = it->second - it->first;
		if (len == 1) return;
		int split = it->first + rand() % (len - 1) + 1;
		if (!okcheck || (isok(line - 1, split) && isok(line + 1, split))) {
			r.splitAt(split);
		}
	}

	bool badsplit(int line) {
		Row& r = lines[line];
		Row& r2 = lines[line -1];
		int pos = rand() % (W + 1);
		rep(i,0,10) {
			auto it = r2.holes.upper_bound(pii(pos+1, 0));
			if (it == r2.holes.begin()) continue;
			--it;
			int w = it->first + rand()%(it->second - it->first);
			if (r.splitAt(w)) return true;
		}
		return false;
	}

	bool isok(int line, int point) {
		if (line < 0 || line >= H) return true;
		return lines[line].isok(point);
	}

	bool isokhole(int line, int L, int R) {
		if (line < 0 || line >= H) return true;
		return lines[line].isokhole(L, R);
	}
};


void filled(int MX) {
	Wall w(1 + rand() % int(2 * sqrt(MX)), MX);
	int splits = rand() % (MX - w.H + 1);
	rep(i,0,splits) {
		w.randsplit(rand() % w.H, true);
	}
	w.output();
}

void filled2(int MX) {
	Wall w(3 + rand() % int(2*sqrt(MX)), MX);
	int splits = rand() % (MX - w.H);
	rep(i,0,splits-1) {
		w.randsplit(rand() % w.H, true);
	}
	rep(i,0,200) {
		int theline = 1 + rand() % (w.H - 2);
		if (w.badsplit(theline)) break;
	}
	w.output();
}

void okholes(int MX) {
	Wall w(1 + rand() % int(2 * sqrt(MX)), MX);
	int holes = rand() % int(4 * sqrt(MX));
	rep(i,0,holes) {
		w.randhole(rand() % (w.H - 1), true);
	}
	int splits = rand() % (MX - w.H + 1);
	rep(i,0,splits) {
		w.randsplit(rand() % w.H, true);
	}
	w.output();
}

void splithole(int MX) {
	Wall w(3 + rand() % int(2*sqrt(MX)), MX);
	int holes = rand() % int(4 * sqrt(MX));
	rep(i,0,holes) {
		w.randhole(rand() % (w.H - 1), true);
	}
	int splits = rand() % (MX - w.H);
	rep(i,0,splits-1) {
		w.randsplit(rand() % w.H, true);
	}
	rep(i,0,200) {
		int theline = 1 + rand() % (w.H - 2);
		if (w.badsplit(theline)) break;
	}
	w.output();
}

void doublehole(int MX) {
	Wall w(3 + rand() % int(2*sqrt(MX)), MX);
	int holes = rand() % int(4 * sqrt(MX));
	rep(i,0,holes) {
		w.randhole(rand() % (w.H - 1), true);
	}
	rep(i,0,200) {
		if (w.subhole(rand() % (w.H - 1))) break;
	}
	int splits = rand() % (MX - w.H);
	rep(i,0,splits-1) {
		w.randsplit(rand() % w.H, true);
	}
	w.output();
}

void pyramid(int MX) {
	printf("%d %d\n", MX, MX/2 - 1);
	rep(i,0,MX/2 - 1) {
		printf("2 %d %d %d %d\n", 0, i+1, MX-(i + 1), i + 1);
	}
}

void pyramid2(int MX) {
	printf("%d %d\n", MX, MX - 1);
	rep(i,0,MX - 1) {
		printf("1 %d %d\n", 0, i+1);
	}
}

int main(int argc, const char** argv) {
	int MX = atoi(argv[1]);
	srand(atoi(argv[argc - 1]));
	string type(argv[2]);
	if (type == "filled") {
		filled(MX);
	}
	if (type == "filled2") {
		filled2(MX);
	}
	if (type == "okholes") {
		okholes(MX);
	}
	if (type == "splithole") {
		splithole(MX);
	}
	if (type == "doublehole") {
		doublehole(MX);
	}
	if (type == "pyramid") {
		pyramid(MX);
	}
	if (type == "pyramid2") {
		pyramid2(MX);
	}
}
