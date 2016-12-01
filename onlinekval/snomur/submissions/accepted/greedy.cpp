#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define sz(x) (int)(x).size()
typedef vector<int> vi;
int main() {
	int T, N, W;
	cin >> T >> N >> W;
	map<int, int> blocks;
	rep(i,0,N) {
		int x;
		cin >> x; 
		blocks[x]++;
	}
	vector<vector<int>> lines;

	while(N) {
		vi line;
		int left = W;
		while (left) {
			auto it = blocks.upper_bound(left);
			if (it == blocks.begin()) break;
			--it;
			line.push_back(it->first);
			it->second--;
			if (it->second==0) blocks.erase(it);
			left -= line.back();
		}
		if (left) break;
		lines.push_back(line);
	}

	cout << sz(lines) << endl;
	for(auto& line : lines) {
		cout << sz(line) << " ";
		int at = 0;
		for(auto& block : line) {
			cout << at << " " << block << " ";
			at += block;
		}
		cout << endl;
	}
}
