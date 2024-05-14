#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a = (b); a < (c); a++)

typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> pii;
typedef vector<pii> vii;

const ll inf = 1e18, maxdays = 111111, maxweight = 111;


int main(){
	int n, m;
	cin >> n >> m;

	vi d(maxdays, 0);
	vector<vii> wares(maxdays);

	rep(i, 0, n){
		int day, weight;
		cin >> day >> weight;
		d[day] += weight;
	}

	rep(i, 0, m){
		int day, weight, cost;
		cin >> weight >> cost >> day;
		wares[day].push_back(pii(weight, cost));
	}

	vii dp;
	dp.push_back(pii(0, inf));
	rep(day, 0, maxdays)
		rep(j, 0, d[day])
			dp.push_back(pii(day, inf));
	dp[dp.size()-1].second = 0;

	vi best(maxweight, inf);
	int curday = maxdays;

	for(int i = dp.size(); i --> 0;){
		int day = dp[i].first;

		while(curday > day){
			curday --;
			for (pii p : wares[curday])
				best[p.first] = min(best[p.first], p.second);
		}
		

		rep(weight, 1, maxweight){
			int target = max(i-weight, 0);
			dp[target].second = min(dp[target].second, dp[i].second+best[weight]);
		}
	}


	cout << dp[0].second << endl;
}
