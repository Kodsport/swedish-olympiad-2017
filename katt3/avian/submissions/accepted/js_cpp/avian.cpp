#include <string>
#include <vector>

#include "avian.h"

using namespace std;

vector<string> encode(int C, int K, int N, string X) {
	vector<string> encoding(4);
	for (int i = 0; i < N; i++) {
		string sub = X.substr(i * 3, 3);
		encoding[0].push_back(sub[0]);
		encoding[1].push_back(sub[1]);
		encoding[2].push_back(sub[2]);
		encoding[3].push_back(sub[0] ^ sub[1] ^ sub[2]);
	}
	return encoding;
}

string decode(int C, int K, int N, vector<string> Y, vector<int> I) {
	string ret;
	for (int i = 0; i < N; i++) {
		char x = 0;
		string add(3, '\0');
		for (int j = 0; j < 3; j++) {
			if (I[j] < 3) {
				add[I[j]] = Y[j][i];
			}
			x ^= Y[j][i];
		}
		for (int j = 0; j < 3; j++) {
			if (add[j] == 0) add[j] = x;
		}
		ret += add;
	}
	return ret;
}
