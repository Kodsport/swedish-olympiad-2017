#include "validator.h"

const int MAX_N = 400001;

void run() {
	string in = Word();
	Endl();
	for (char c : in) {
		assert(c=='R'||c=='G'||c=='B');
	}
	assert(in.size() >= 3 && in.size() <= MAX_N);
}
