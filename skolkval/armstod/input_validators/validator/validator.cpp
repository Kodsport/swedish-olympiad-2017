#include "validator.h"
#include <cstring>
#include <vector>

typedef long long ll;

void run() {
    int maxN = Arg("maxN", 30);
    int firstI = Arg("firstI",0);

    int n = Int(5, maxN);
    Endl();
    string s = Line();
    if (s.size() != n){
        die("The string does not have size n.");
    }
    
    for (int i=0; i<s.size() ; i++){
        if (firstI == 1 && s[i] != 'I' && i==0){
            die("First character is not an I.");
        }
        else if (!(s[i] == 'V' || s[i] == 'H' || s[i] == 'A' || s[i] == 'B' || s[i] == 'I')){
            die("String contains invalid character. (not part of 'VHABI')");
        }
    }
    Eof();
}