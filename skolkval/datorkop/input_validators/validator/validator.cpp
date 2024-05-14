#include "validator.h"
#include <cstring>
#include <vector>

typedef long long ll;



void run() {
    int minN = Arg("minN", 2);
    int maxN = Arg("maxN", 1000);
    int maxXY = Arg("maxXY", 1000);


    int x = Int(0, maxXY);
    Space();
    int a = Int(1, 1000);
    Space();
    int y = Int(0, maxXY);
    Space();
    int b = Int(1, 1000);
    Space();
    int N = Int(minN, maxN);
    Endl();
    
    
    Eof();
}