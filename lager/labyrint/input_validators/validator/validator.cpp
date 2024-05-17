#include <bits/stdc++.h>
#include "validator.h"


using namespace std;


void run() {
	string in = Line();
	for (auto& c : in)
	{
		assert(c=='R'||c=='G'||c=='B');
	}

	Eof();
}
