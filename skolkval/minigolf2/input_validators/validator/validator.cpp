#include "validator.h"
#include <cstring>
#include <vector>

typedef long long ll;

void run() {
    int maxA = Arg("maxA", 10);
    int minA = Arg("minA",1);

    int n = Int(2, 10);
    Endl();
    vector<int> v = SpacedInts<int>(n, minA, maxA);
    Eof();
}