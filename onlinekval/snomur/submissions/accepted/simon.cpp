#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<pii> rev(int W, const vector<pii>& v) {
	vector<pii> ret;
	trav(x, v) {
		int pos = x.first, len = x.second;
		pos = W - pos - len;
		ret.emplace_back(pos, len);
	}
	reverse(all(ret));
	return ret;
}

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int T, N, W;
	cin >> T >> N >> W;
	vi parts(N);
	rep(i,0,N) {
		cin >> parts[i];
		assert(1 <= parts[i] && parts[i] <= W);
	}
	sort(all(parts));
	vector<pii> last = {pii(0, W)};
	vector<vector<pii>> wall;
	auto canPlace = [&](int pos) -> bool {
		if (pos == 0 || pos == W) return true;
		assert(pos > 0);
		assert(!last.empty() && last[0].first == 0);
		auto it = lower_bound(all(last), pii(pos, -1));
		--it;
		return it->first < pos && pos < it->first + it->second;
	};
	auto hasHole = [&](int from, int to) -> bool {
		assert(from < to);
		auto it = upper_bound(all(last), pii(from, W+1));
		--it;
		auto it2 = lower_bound(all(last), pii(to, -1));
		--it2;
		if (it2->first + it2->second < to) return true;
		while (it != it2) {
			auto it3 = it; ++it3;
			if (it->first + it->second != it3->first) return true;
			it = it3;
		}
		return false;
	};
	int it = 0;
	while (!parts.empty()) {
		vector<pii> cur;
		vector<pii> wallpart;
		int at = 0;
		while (at != W) {
			bool success = false;
			for (int j = sz(parts); j--;) {
				int s = parts[j];
				if (at + s > W) continue;
				if (!canPlace(at + s)) continue;
				wallpart.emplace_back(at, s);
				if (cur.empty()) cur.emplace_back(0, s);
				else cur.back().second += s;
				parts.erase(parts.begin() + j);
				at += s;
				success = true;
				break;
			}

			if (!success) {
				// We've failed, unless we can put something at the edge,
				// possibly after removing the last placed thing.
				auto putAtEdge = [&]() -> bool {
					for (int j = sz(parts); j--;) {
						int s = parts[j];
						int pos = W - s;
						if (pos < at) continue;
						if (!canPlace(pos)) continue;
						if (hasHole(at, pos)) return false;
						cur.emplace_back(pos, s);
						wallpart.emplace_back(pos, s);
						parts.erase(parts.begin() + j);
						at = W;
						return true;
					}
					return false;
				};

				if (!putAtEdge()) {
					if (wallpart.size() <= 1) goto done;
					int s;
					tie(at, s) = wallpart.back();
					wallpart.pop_back();
					parts.push_back(s);
					sort(all(parts));
					cur.back().second -= s;
					if (!putAtEdge()) goto done;
				}
				break;
			}
		}
		wall.push_back(it % 2 ? wallpart : rev(W, wallpart));
		last = rev(W, cur);
		it++;
	}
done:

	cout << ' ' << wall.size() << "  \n";
	trav(w, wall) {
		cout << ' ' << w.size();
		trav(x, w) cout << "  " << x.first << "  " << x.second;
		cout << "  \n";
	}
	cout << flush;
	exit(0);
}
