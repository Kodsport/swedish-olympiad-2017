#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a = (b); a < (c); a++)

typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

struct SegmentTree {
	vi st;
	int n;
	SegmentTree(){}
	SegmentTree(int n){
		this->n = n;
		st.assign(3*n, 0);
	}

	int query(int l, int r) {
		int ret = 0;
		for(l += n, r += n; l < r; l /= 2, r /= 2){
			if (l & 1) ret = max(ret, st[l++]);
			if (r & 1) ret = max(ret, st[--r]);
		}
		return ret;
	}

	void set(int i, int k){
		st[i += n] = k;
		while(i > 0)
			st[i/2] = max(st[i], st[i^1]), i /= 2;
	}
};

int N, M, S, P;
int NC = 0; //compressed length

int main(){
	cin >> N >> M >> S >> P;
	int ans = 0;

	vii trips(M);
	rep(i, 0, M)
		cin >> trips[i].first >> trips[i].second;

	vi snow(N);
	rep(i, 0, S){
		int pos;
		cin >> pos;
		snow[pos-1] = 1;
	}

	vi compressed(N);
	rep(i, 0, N){
		compressed[i] = NC;
		if (snow[i])
			NC++;
	}
	NC ++;

	vi started(NC+1), ended(NC+1);
	for(pii trip : trips){
		int from = compressed[trip.first-1], to = compressed[trip.second-1];

		if (from > to)
			swap(from, to);
		if (from == to){
			ans ++;
			continue;
		}

		started[from+1]++, ended[to]++;
	}

	rep(i, 1, NC+1)
		started[i] += started[i-1], ended[i] += ended[i-1];

	vvi dp(NC, vi(P+1));
	vector<SegmentTree> diagonal(NC+P+1, SegmentTree(P+1)); //diagonals

	rep(p, 0, P+1)
		for(int i = NC-1; i --> 0;){
			int best = dp[i+1][p];
			best = max(best, diagonal[i+p].query(0, p+1)-started[i]);

			dp[i][p] = best;
			diagonal[i+p].set(p, best+ended[i]);
		}

	cout << dp[0][P]+1 << endl;

	return 0;
}

