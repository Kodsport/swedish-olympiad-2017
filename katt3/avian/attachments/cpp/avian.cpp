#include <iostream>
#include <vector>

#include "avian.h"

using namespace std;

vector<string> encode(int C, int K, int N, string X) {
	return vector<string>(K, string(N, '0'));
}

string decode(int C, int K, int N, vector<string> Y, vector<int> I) {
	return string(C*N, '0');
}
