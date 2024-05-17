#include "validator.h"
#include "bits/stdc++.h"

typedef long long ll;

void run() {
    string mode = Arg("mode", "none");
    int maxN = Arg("maxN", 100000);
    
    int n = Int(1, maxN);
    Endl();

    unordered_set<int> T;
    for (int i = 0; i < n; i++){
        int a = Int(-1000000000, 1000000000);
        Space();
        int b = Int(-1000000000, 1000000000);
        Space();
        int c = Int(-1000000000, 1000000000);
        Space();
        int t = Int(1,100000);
        Endl();
	T.insert(t);
	if (mode == "convex") {
	    assert(a > 0);
	}
	else if (mode == "concave") {
	    assert(a < 0);
	}
    }
    if (mode == "same") assert((int) T.size() == 1);
    
    
    
    Eof();
}
