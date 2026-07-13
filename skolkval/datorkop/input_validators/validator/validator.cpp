#include "validator.h"

const int MAX_N = 1000;
const int MAX_XY = 1000;
const int MAX_AB = 1000;

void run() {
    int maxXY = Arg("maxXY", MAX_XY);

    int x = Int(0, maxXY);
    Space();
    int a = Int(1, MAX_AB);
    Space();
    int y = Int(0, maxXY);
    Space();
    int b = Int(1, MAX_AB);
    Space();
    int N = Int(2, Arg("maxN", MAX_N));
    Endl();
}
