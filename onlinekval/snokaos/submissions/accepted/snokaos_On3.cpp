#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a = (b); a < (c); a++)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int N, M, P, S;
vvi canMoveFrom;
vi containsSnow;


vvvi dp;

int f(int pos, int clearFrom, int removalsLeft){
	// DP
	if (dp[pos][clearFrom][removalsLeft] != -1)
		return dp[pos][clearFrom][removalsLeft];


	int finished = canMoveFrom[pos][clearFrom];

	// If we are at the end, we can't remove more snow.
	if (pos == N-1)
		return dp[pos][clearFrom][removalsLeft] = finished;

	int best; // The best addition we could find
	if (containsSnow[pos]){
		// Don't remove snow, our station and
		// earlier is now inaccessible.
		best = f(pos+1, pos+1, removalsLeft);

		// Remove snow, accessibility backwards isn't changed.
		if (removalsLeft > 0)
			best = max(best, f(pos+1, clearFrom, removalsLeft-1));
	
	} else {
		// No need to remove any snow.
		best = f(pos+1, clearFrom, removalsLeft);
	}

	return dp[pos][clearFrom][removalsLeft] = (finished+best);
}

int main(){
	cin >> N >> M >> S >> P;


	// Read the travel routes.
	canMoveFrom = vvi(N, vi(N, 0));
	rep(i, 0, M){
		int a, b;
		cin >> a >> b;
		a--, b--;

		// Flip the travels so everyone travels right.
		if (b < a)
			swap(a, b);
		canMoveFrom[b][a] ++;
	}

	// Build an accumulating vector:
	// If we stand at position i and 
	// snow is removed from position j,
	// how many passengers can move to i?
	rep(i, 0, N)
		for(int j = N-1; j --> 0;)
			canMoveFrom[i][j] += canMoveFrom[i][j+1];


	// Read the snow
	containsSnow.resize(N, 0);
	rep(i, 0, S){
		int pos;
		cin >> pos;
		pos --;
		containsSnow[pos] = 1;
	}

	// Run the DP function
	dp = vvvi(N, vvi(N, vi(N, -1)));
	cout << f(0, 0, P) << endl;
	return 0;
}