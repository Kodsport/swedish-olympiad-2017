#include "validator.h"
#include <cstring>
#include <vector>

typedef long long ll;

void run() {
    int maxN = Arg("maxN", 1e12);
    int minN = Arg("minN",1);

    int n = Int(minN, maxN);
    Endl();
    Eof();
}