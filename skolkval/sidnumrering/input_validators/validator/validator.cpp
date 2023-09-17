#include "validator.h"
#include <cstring>
#include <vector>

typedef long long ll;

void run() {
    ll maxN = Arg("maxN", 1e12);
    ll minN = Arg("minN",1);

    ll n = Int(minN, maxN);
    Endl();
    Eof();
}