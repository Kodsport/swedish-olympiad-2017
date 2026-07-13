#include <bits/stdc++.h>

using namespace std;

int a, b;
map<tuple<int, int, int, int>, bool> memo;

bool dp(int left, int x, int y, int last) {
	if (left == 0) return true;
	if (last * left > x*a + y*b) return false;

	auto it = memo.find({left, x, y, last});
	if (it != memo.end()) return it->second;

	bool ans = false;
	for (int i = 0; i <= x; i++) {
		int cury = max(0, (last - i*a + b-1) / b);

		if (cury <= y && dp(left-1, x-i, y-cury, i*a + cury*b)) {
			ans = true;
			break;
		}

		if (i*a >= last) break;
	}

	return memo[{left, x, y, last}] = ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int x, y, n;
	cin >> x >> a >> y >> b >> n;
	
	int ans = 0;
	for (int i = 0; i <= x; i++) {
		for (int j = 0; j <= y; j++) {
			int cur = i*a + j*b;
			if (!dp(n-1, x-i, y-j, cur)) continue;
			ans = max(ans, cur);
		}
	}

	cout << ans << '\n';
}

