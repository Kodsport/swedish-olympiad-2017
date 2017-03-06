#include <iostream>
#include <string>
#include <vector>

#include "avian.h"

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int C, K, N;
	string X;
	cin >> C >> K >> N >> X;
	vector<int> I(C);
	for (int i = 0; i < C; i++) {
		cin >> I[i];
	}

	vector<string> encoder = encode(C, K, N, X);
	if (encoder.size() != (size_t)K) {
		cerr << "Encoder gave " << encoder.size() << " strings, expected " << K << endl;
		return 0;
	}
	for (const string& s : encoder) {
		if (s.size() != (size_t)N) {
			cerr << "Encoder gave string of length " << s.size() << ", expected " << N << endl;
			return 0;
		}
		for (char c : s) {
			if (c != '0' && c != '1') {
				cerr << "Encoder gave string containing character " << c << ", expected either 0 or 1" << endl;
				return 0;
			}
		}
	}
	vector<string> subset;
	for (int i = 0; i < C; i++) {
		subset.push_back(encoder[I[i]]);
	}
	string decoded = decode(C, K, N, subset, I);
	cout << decoded << endl;
}
