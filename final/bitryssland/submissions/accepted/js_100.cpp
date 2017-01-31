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
    int N, M;
	cin >> N >> M;
    vector<ll> A(64);
    vector<ll> B(64);
	rep(i,0,N) cin >> A[i];
	rep(i,0,M) {
		ll b;
		cin >> b;
		rep(j,0,64) {
			if (b%2) B[j]++;
			b /= 2;
		}
	}
	rep(i,0,62) {
		if (A[i] < B[i]) {
			cout << "nej" << endl;
			return 0;
		}
		A[i] -= B[i];
		A[i + 1] += A[i] / 2;
	}
	cout << "ja" << endl;
}
