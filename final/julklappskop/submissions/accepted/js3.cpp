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

int main() {
	int K, N;
	cin >> K >> N;
	assert(K <= 8 && N <= 100000);
	map<int, vector<pii>> pruned;
	rep(i,0,K) {
		vector<pii> likes;
		rep(j,0,N) {
			int happy;
			cin >> happy;
			likes.emplace_back(-happy, j);
		}
		sort(all(likes));
		rep(j,0,K) {
			int happy = -likes[j].first,
				name = likes[j].second;
			pruned[name].emplace_back(i, happy);
		}
	}
	vector<int> mhappy(1<<K, 0);
	trav(it, pruned) {
		vector<int> nmhappy = mhappy;
		rep(i,0,1<<K) {
			trav(it2, it.second) {
				if (i & (1 << it2.first)) continue;
				nmhappy[i | (1 << it2.first)] = max(
					nmhappy[i | (1 << it2.first)],
					mhappy[i] + it2.second
				);
			}
		}
		mhappy.swap(nmhappy);
	}
	cout << mhappy.back() << endl;
}
