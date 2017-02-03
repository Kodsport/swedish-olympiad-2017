#include <bits/stdc++.h>
using namespace std;

#define rep(i,f,t) for (int i = f; i < (t); ++i)
#define all(x) x.begin(), x.end()
#define trav(a,x) for (auto& a : x)
// #define double long double

// max ax^2 + bx + c, lo <= x <= hi
double maximize(double a, double b, double c, double lo, double hi) {
	assert(lo <= hi);
	auto ev = [a,b,c](double x) { return a*x*x + b*x + c; };
	double res = max(ev(lo), ev(hi));
	// df/dx = 0 => x = -b/2a
	if (a != 0) { // (not really necessary, since nan is fine, but eh)
		double midp = -b / 2 / a;
		if (lo <= midp && midp <= hi)
			res = max(res, ev(midp));
	}
	return res;
}

int main() {
	int N;
	cin >> N;
	vector<pair<double, tuple<double, double, double>>> points;
	double A=0, B=0, C=0;
	rep(i,0,N) {
		double a, b, c, t;
		cin >> a >> b >> c >> t;
		assert(-maximize(-a,-b,-c,0,t) > 1e-5);
		A += a;
		B += b;
		C += c;
		points.push_back({t, make_tuple(a,b,c)});
	}
	sort(all(points));
	double lastt = 0;
	double res = 0;
	trav(p, points) {
		double t = p.first, a, b, c;
		tie(a,b,c) = p.second;
		res = max(res, maximize(A, B, C, lastt, t));
		lastt = t;
		A -= a;
		B -= b;
		C -= c;
	}
	cout << setprecision(10) << fixed << res << endl;
}
